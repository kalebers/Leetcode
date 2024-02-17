#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int> ladderQueue;

        for (int i = 0; i < heights.size() - 1; i++) {
            int diff = heights[i + 1] - heights[i];

            if (diff > 0) {
                if (ladders > 0) {
                    ladderQueue.push(diff);
                    ladders--;
                } else if (!ladderQueue.empty() && diff > ladderQueue.top()) {
                    bricks -= ladderQueue.top();
                    ladderQueue.pop();
                    ladderQueue.push(diff);
                } else {
                    bricks -= diff;
                }

                if (bricks < 0) {
                    return i;
                }
            }
        }

        return heights.size() - 1;
    }
};
