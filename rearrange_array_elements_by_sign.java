// You are given a 0-indexed integer array nums of even length consisting of an equal number of positive and negative integers.
// You should rearrange the elements of nums such that the modified array follows the given conditions:
// Every consecutive pair of integers have opposite signs.
// For all integers with the same sign, the order in which they were present in nums is preserved.
// The rearranged array begins with a positive integer.
// Return the modified array after rearranging the elements to satisfy the aforementioned conditions.

import java.util.LinkedList;

class Solution {
    public int[] rearrangeArray(int[] nums) {
        int n = nums.length;
        LinkedList<Integer> positive = new LinkedList<>();
        LinkedList<Integer> negative = new LinkedList<>();

        // Separate positive and negative numbers
        for (int num : nums) {
            if (num >= 0) {
                positive.add(num);
            } else {
                negative.add(num);
            }
        }

        // Merge positive and negative numbers with alternating signs
        int[] result = new int[n];
        int i = 0;
        while (!positive.isEmpty() && !negative.isEmpty()) {
            result[i++] = positive.poll();
            result[i++] = negative.poll();
        }

        // Copy the remaining positive or negative numbers
        while (!positive.isEmpty()) {
            result[i++] = positive.poll();
        }
        while (!negative.isEmpty()) {
            result[i++] = negative.poll();
        }

        return result;
    }
}
