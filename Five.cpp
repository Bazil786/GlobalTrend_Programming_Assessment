#include <iostream>
#include <vector>
#include <algorithm> // Needed for reverse function
using namespace std;

void rotate(vector<int>& nums, int k) {
    int n = nums.size();
    if (n == 0 || k % n == 0) return;

    k = k % n;

    reverse(nums.begin(), nums.end());
    reverse(nums.begin(), nums.begin() + k);
    reverse(nums.begin() + k, nums.end());
}

void printArray(const vector<int>& nums) {
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;
}


int main() {
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
    int k = 3;
    printArray(nums);
    rotate(nums, k);
    printArray(nums);

    return 0;
}
