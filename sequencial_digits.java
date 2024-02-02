//An integer has sequential digits if and only if each digit in the number is one more than the previous digit.
//Return a sorted list of all the integers in the range [low, high] inclusive that have sequential digits.


import java.util.ArrayList;
import java.util.List;

public class Solution {
   public static List<Integer> sequentialDigits(int low, int high) {
        List<Integer> result = new ArrayList<>();

        for (int digit = 1; digit <= 9; digit++) {
            int num = digit;
            int nextDigit = digit + 1;

            while (num <= high && nextDigit <= 9) {
                num = num * 10 + nextDigit;
                if (num >= low && num <= high) {
                    result.add(num);
                }
                nextDigit++;
            }
        }

        result.sort(null);
        return result;
    }

    public static void main(String[] args) {
        int low1 = 100, high1 = 300;
        System.out.println("Example 1: " + sequentialDigits(low1, high1));

        int low2 = 1000, high2 = 13000;
        System.out.println("Example 2: " + sequentialDigits(low2, high2));
    }
}
