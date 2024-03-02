#include <vector>
#include <algorithm>

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n);

        for (int i = 0; i < n; ++i) {
            result[i] = nums[i] * nums[i];
        }

        sort(result.begin(), result.end());

        return result;
    }
};
