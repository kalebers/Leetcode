# Problem definition:
# Given an input string s and a pattern p, implement regular expression matching with support for '.' and '*' where:
# '.' Matches any single character.​​​​
# '*' Matches zero or more of the preceding element.
# The matching should cover the entire input string (not partial).

# 1 <= s.length <= 20
# 1 <= p.length <= 20
# s contains only lowercase English letters.
# p contains only lowercase English letters, '.', and '*'.
# It is guaranteed for each appearance of the character '*', there will be a previous valid character to match.

class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        # Create a 2D dp array to store intermediate results
        dp = [[False] * (len(p) + 1) for _ in range(len(s) + 1)]

        # An empty pattern matches an empty string
        dp[0][0] = True

        # Handle patterns with '*'
        for j in range(1, len(p) + 1):
            if p[j - 1] == '*':
                dp[0][j] = dp[0][j - 2]

        # Fill in the dp array
        for i in range(1, len(s) + 1):
            for j in range(1, len(p) + 1):
                if p[j - 1] == s[i - 1] or p[j - 1] == '.':
                    dp[i][j] = dp[i - 1][j - 1]
                elif p[j - 1] == '*':
                    dp[i][j] = dp[i][j - 2] or (dp[i - 1][j] if s[i - 1] == p[j - 2] or p[j - 2] == '.' else False)

        return dp[len(s)][len(p)]

        # Example usage
        print(isMatch("aa", "a"))    # Output: False
        print(isMatch("aa", "a*"))   # Output: True
        print(isMatch("ab", ".*"))   # Output: True
