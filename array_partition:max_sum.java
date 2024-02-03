//Given an integer array arr, partition the array into (contiguous) subarrays of length at most k. After partitioning, each subarray has their values changed to become the maximum value of that subarray.
//Return the largest sum of the given array after partitioning. Test cases are generated so that the answer fits in a 32-bit integer.


public class Solution {
    public int maxSumAfterPartitioning(int[] arr, int k) {
        int n = arr.length;
        int[] dp = new int[n];

        for (int i = 0; i < n; i++) {
            int maxVal = Integer.MIN_VALUE;

            for (int j = 1; j <= k && i - j + 1 >= 0; j++) {
                maxVal = Math.max(maxVal, arr[i - j + 1]);

                if (i - j >= 0) {
                    dp[i] = Math.max(dp[i], dp[i - j] + maxVal * j);
                } else {
                    dp[i] = Math.max(dp[i], maxVal * j);
                }
            }
        }

        return dp[n - 1];
    }

    public static void main(String[] args) {
        Solution solution = new Solution();

        // Example usage:
        int[] arr = {1, 15, 7, 9, 2, 5, 10};
        int k = 3;
        int result = solution.maxSumAfterPartitioning(arr, k);
        System.out.println("Maximum sum after partitioning: " + result);
    }
}
