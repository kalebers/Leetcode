// Given two strings s and t of lengths m and n respectively, return the minimum window 
// substring of s such that every character in t (including duplicates) is included in the window. If there is no such substring, return the empty string "".

#include <iostream>
#include <unordered_map>
#include <climits>

class Solution {
public:
    string minWindow(string s, string t) {
        std::unordered_map<char, int> charCount;
        int requiredChars = t.length();

        for (char c : t) {
            charCount[c]++;
        }

        int left = 0, right = 0, minLength = INT_MAX, minLeft = 0;

        while (right < s.length()) {
            if (charCount[s[right]] > 0) {
                requiredChars--;
            }
            charCount[s[right]]--;
            right++;

            while (requiredChars == 0) {
                if (right - left < minLength) {
                    minLength = right - left;
                    minLeft = left;
                }

                charCount[s[left]]++;
                if (charCount[s[left]] > 0) {
                    requiredChars++;
                }
                left++;
            }
        }

        return (minLength == INT_MAX) ? "" : s.substr(minLeft, minLength);
    }
};

// example
int main() {
    Solution solution;

    std::string s = "ADOBECODEBANC";
    std::string t = "ABC";

    std::string result = solution.minWindow(s, t);

    std::cout << "Minimum Window Substring: " << result << std::endl;

    return 0;
}
