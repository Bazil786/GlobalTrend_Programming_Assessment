#include <iostream>
#include <queue>
#include <sstream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Codec {
public:
    string serialize(TreeNode* root) {
        if (!root) return "";

        stringstream ss;
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            if (node) {
                ss << node->val << " ";
                q.push(node->left);
                q.push(node->right);
            } else {
                ss << "null ";
            }
        }

        return ss.str();
    }

    TreeNode* deserialize(const string& data) {
        if (data.empty()) return nullptr;

        stringstream ss(data);
        string val;
        getline(ss, val, ' ');
        TreeNode* root = new TreeNode(stoi(val));
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            if (getline(ss, val, ' ')) {
                if (val != "null") {
                    node->left = new TreeNode(stoi(val));
                    q.push(node->left);
                }
            }

            if (getline(ss, val, ' ')) {
                if (val != "null") {
                    node->right = new TreeNode(stoi(val));
                    q.push(node->right);
                }
            }
        }

        return root;
    }
};

void printTree(TreeNode* root) {
    if (!root) return;

    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        TreeNode* node = q.front();
        q.pop();
        if (node) {
            cout << node->val << " ";
            q.push(node->left);
            q.push(node->right);
        } else {
            cout << "null ";
        }
    }
    cout << endl;
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(5);

    Codec codec;
    string serialized = codec.serialize(root);
    cout << "Serialized: " << serialized << endl;

    TreeNode* deserializedRoot = codec.deserialize(serialized);
    cout << "Deserialized tree (level order): ";
    printTree(deserializedRoot);
    return 0;
}
