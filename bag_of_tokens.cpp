#include <vector>
#include <algorithm>

class Solution {
public:
    int bagOfTokensScore(std::vector<int>& tokens, int power) {
        // Sort tokens in ascending order
        std::sort(tokens.begin(), tokens.end());

        int score = 0, maxScore = 0;
        int left = 0, right = tokens.size() - 1;

        while (left <= right) {
            // Face-up: Play the smallest token if power is enough
            if (power >= tokens[left]) {
                power -= tokens[left++];
                ++score;
                maxScore = std::max(maxScore, score);
            }
            // Face-down: Play the largest token to gain power
            else if (score > 0) {
                power += tokens[right--];
                --score;
            }
            // If none of the above, we cannot make any more moves
            else {
                break;
            }
        }

        return maxScore;
    }
};
