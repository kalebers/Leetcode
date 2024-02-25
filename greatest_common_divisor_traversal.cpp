#include <vector>
#include <unordered_map>

class Solution {
private:
    std::unordered_map<int, int> parent;

    int find(int x) {
        if (parent.find(x) == parent.end()) {
            parent[x] = x;
        } else if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);

        if (rootX != rootY) {
            parent[rootX] = rootY;
        }
    }

    int gcd(int a, int b) {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

public:
    bool canTraverseAllPairs(std::vector<int>& nums) {
        int n = nums.size();

        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (gcd(nums[i], nums[j]) > 1) {
                    unite(i, j);
                }
            }
        }

        int representative = find(0);

        for (int i = 1; i < n; ++i) {
            if (find(i) != representative) {
                return false;
            }
        }

        return true;
    }
};
