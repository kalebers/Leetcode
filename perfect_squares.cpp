// Given an integer n, return the least number of perfect square numbers that sum to n.
// A perfect square is an integer that is the square of an integer; in other words, it is the product of some integer with itself. For example, 1, 4, 9, and 16 are perfect squares while 3 and 11 are not.

#include <vector>
#include <climits>
#include <cmath>

class Solution {
public:
    int numSquares(int n) {
        // Create a vector to store the least number of perfect squares for each number up to n
        std::vector<int> dp(n + 1, INT_MAX);

        // The least number of perfect squares for 0 is 0
        dp[0] = 0;

        // Iterate from 1 to n
        for (int i = 1; i <= n; ++i) {
            // Iterate over all possible perfect squares less than or equal to i
            for (int j = 1; j * j <= i; ++j) {
                // Update dp[i] by choosing the minimum of the current value and 1 plus the value at (i - j*j)
                dp[i] = std::min(dp[i], dp[i - j * j] + 1);
            }
        }

        // The final result is stored in dp[n]
        return dp[n];
    }
};


