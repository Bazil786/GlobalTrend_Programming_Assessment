#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int maxDifference(vector<int>& nums) {
    if (nums.size() < 2) {
        return 0;
    }

    int minVal = INT_MAX;
    int maxDiff = INT_MIN;

    for (int num : nums) {
        minVal = min(minVal, num);
        maxDiff = max(maxDiff, num - minVal);
    }

    return maxDiff;
}

int main() {
    vector<int> nums = {7, 1, 5, 3, 6, 4};

    int result = maxDifference(nums);
    cout << "Maximum difference between any two elements in the array is: " << result << endl;

    return 0;
}