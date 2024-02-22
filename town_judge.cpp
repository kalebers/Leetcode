// In a town, there are n people labeled from 1 to n. There is a rumor that one of these people is secretly the town judge.

// If the town judge exists, then:
// The town judge trusts nobody.
// Everybody (except for the town judge) trusts the town judge.
// There is exactly one person that satisfies properties 1 and 2.
// You are given an array trust where trust[i] = [ai, bi] representing that the person labeled ai trusts the person labeled bi. If a trust relationship does not exist in trust array, then such a trust relationship does not exist.

// Return the label of the town judge if the town judge exists and can be identified, or return -1 otherwise.



#include <vector>

class Solution {
public:
    int findJudge(int n, std::vector<std::vector<int>>& trust) {
        std::vector<int> inDegree(n + 1, 0);
        std::vector<int> outDegree(n + 1, 0);

        for (const auto& t : trust) {
            outDegree[t[0]]++; // Increase out-degree for the person who trusts
            inDegree[t[1]]++;  // Increase in-degree for the person being trusted
        }

        for (int i = 1; i <= n; ++i) {
            if (inDegree[i] == n - 1 && outDegree[i] == 0) {
                return i; // Found the town judge
            }
        }

        return -1; // No town judge found
    }
};
