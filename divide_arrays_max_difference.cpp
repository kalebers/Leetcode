// You are given an integer array nums of size n and a positive integer k.

// Divide the array into one or more arrays of size 3 satisfying the following conditions:

// Each element of nums should be in exactly one array.
// The difference between any two elements in one array is less than or equal to k.
// Return a 2D array containing all the arrays. If it is impossible to satisfy the conditions, return an empty array. And if there are multiple answers, return any of them.


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
   vector<vector<int>> divideArray(vector<int>& nums, int k) {
    // Step 1: Sort the array
    sort(nums.begin(), nums.end());

    // Step 2: Create a 2D vector to store resulting arrays
    vector<vector<int>> result;

    // Step 3: Iterate through the sorted array
    for (int i = 0; i < nums.size(); i += 3) {
        // Check if it's possible to form an array of size 3
        if (i + 2 < nums.size() && nums[i + 2] - nums[i] <= k) {
            // Form an array and add it to the result
            result.push_back({nums[i], nums[i + 1], nums[i + 2]});
        } else {
            // If not possible, return an empty array
            return {};
        }
    }

    // Step 4: Return the resulting 2D vector
    return result;
}

int main() {
    // Example 1
    vector<int> nums1 = {1, 3, 4, 8, 7, 9, 3, 5, 1};
    int k1 = 2;
    vector<vector<int>> result1 = divideArray(nums1, k1);

    cout << "Example 1:\n";
    for (const auto& arr : result1) {
        cout << "[";
        for (int num : arr) {
            cout << num << " ";
        }
        cout << "]";
    }
    cout << endl;

    // Example 2
    vector<int> nums2 = {1, 3, 3, 2, 7, 3};
    int k2 = 3;
    vector<vector<int>> result2 = divideArray(nums2, k2);

    cout << "Example 2:\n";
    if (result2.empty()) {
        cout << "Empty array (impossible to satisfy conditions)\n";
    } else {
        for (const auto& arr : result2) {
            cout << "[";
            for (int num : arr) {
                cout << num << " ";
            }
            cout << "]";
        }
        cout << endl;
    }

    return 0;
    }
};
