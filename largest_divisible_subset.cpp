// Given a set of distinct positive integers nums, return the largest subset answer such that every pair (answer[i], answer[j]) of elements in this subset satisfies:
// answer[i] % answer[j] == 0, or
// answer[j] % answer[i] == 0
// If there are multiple solutions, return any of them.


#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<int> largestDivisibleSubset(std::vector<int>& nums) {
        if(nums.empty()) {
            return {};
        }

        std::sort(nums.begin(), nums.end());
        std::vector<int> dp(nums.size(), 1); // dp[i] stores the size of the largest subset ending with nums[i]
        std::vector<int> prev(nums.size(), -1); // prev[i] stores the index of the previous element in the largest subset

        int max_index = 0; // Index of the last element in the largest subset

        for(int i = 1; i < nums.size(); ++i) {
            for(int j = 0; j < i; ++j) {
                if(nums[i] % nums[j] == 0 && dp[i] < dp[j] + 1) {
                    dp[i] = dp[j] + 1;
                    prev[i] = j;
                }
            }
            if(dp[i] > dp[max_index]) {
                max_index = i;
            }
        }

        std::vector<int> result;
        while(max_index != -1) {
            result.push_back(nums[max_index]);
            max_index = prev[max_index];
        }

        return result;
    }
};
