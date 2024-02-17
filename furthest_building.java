// You are given an integer array heights representing the heights of buildings, some bricks, and some ladders.
// You start your journey from building 0 and move to the next building by possibly using bricks or ladders.
// While moving from building i to building i+1 (0-indexed),
// If the current building's height is greater than or equal to the next building's height, you do not need a ladder or bricks.
// If the current building's height is less than the next building's height, you can either use one ladder or (h[i+1] - h[i]) bricks.
// Return the furthest building index (0-indexed) you can reach if you use the given ladders and bricks optimally.


import java.util.PriorityQueue;

class Solution {
    public int furthestBuilding(int[] heights, int bricks, int ladders) {
        PriorityQueue<Integer> ladderQueue = new PriorityQueue<>((a, b) -> b - a);
        
        for (int i = 0; i < heights.length - 1; i++) {
            int diff = heights[i + 1] - heights[i];
            
            if (diff > 0) {
                if (ladders > 0) {
                    ladderQueue.offer(diff);
                    ladders--;
                } else if (!ladderQueue.isEmpty() && diff > ladderQueue.peek()) {
                    bricks -= ladderQueue.poll();
                    ladderQueue.offer(diff);
                } else {
                    bricks -= diff;
                }
                
                if (bricks < 0) {
                    return i;
                }
            }
        }
        
        return heights.length - 1;
    }
}
