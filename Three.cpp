#include <iostream>
#include <climits>
using namespace std;
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
int maxPathSumHelper(TreeNode* root, int& maxSum) {
    if (!root) return 0;
    int leftSum = max(0, maxPathSumHelper(root->left, maxSum));
    int rightSum = max(0, maxPathSumHelper(root->right, maxSum));
    int currentMax = root->val + leftSum + rightSum;
    maxSum = max(maxSum, currentMax);
    return root->val + max(leftSum, rightSum);
}
int maxPathSum(TreeNode* root) {
    int maxSum = INT_MIN;
    maxPathSumHelper(root, maxSum);
    return maxSum;
}
TreeNode* newNode(int val) {
    return new TreeNode(val);
}

int main() {
    TreeNode* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    cout << "The maximum path sum is: " << maxPathSum(root) << endl;
    delete root->left;
    delete root->right;
    delete root;
    return 0;
}
