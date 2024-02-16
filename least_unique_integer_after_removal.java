// Given an array of integers arr and an integer k. Find the least number of unique integers after removing exactly k elements.

import java.util.HashMap;
import java.util.Map;
import java.util.PriorityQueue;

class Solution {
    public int findLeastNumOfUniqueInts(int[] arr, int k) {
        // Count the frequency of each integer
        Map<Integer, Integer> frequencyMap = new HashMap<>();
        for (int num : arr) {
            frequencyMap.put(num, frequencyMap.getOrDefault(num, 0) + 1);
        }

        // Use a PriorityQueue to store frequencies in ascending order
        PriorityQueue<Integer> minHeap = new PriorityQueue<>(frequencyMap.values());

        // Remove the least frequent integers until k becomes 0
        while (k > 0) {
            int minFrequency = minHeap.poll();
            if (minFrequency <= k) {
                k -= minFrequency;
            } else {
                minHeap.offer(minFrequency - k);
                k = 0;
            }
        }

        // The remaining size of the PriorityQueue is the least number of unique integers
        return minHeap.size();
    }
}
