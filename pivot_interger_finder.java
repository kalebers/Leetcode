class Solution {
    public int pivotInteger(int n) {
        int totalSum = n * (n + 1) / 2; // Sum of numbers from 1 to n
        int leftSum = 0;
        
        for (int x = 1; x <= n; x++) {
            int rightSum = totalSum - leftSum - x; // Subtract x because it's counted in both sums
            if (leftSum == rightSum)
                return x;
            leftSum += x;
        }
        
        return -1;
    }
}
