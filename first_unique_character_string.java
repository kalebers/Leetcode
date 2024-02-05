// Given a string s, find the first non-repeating character in it and return its index. If it does not exist, return -1


public class Solution {

    public static int firstUniqChar(String s) {
        // Creating an array to store the frequency of each character
        int[] charFrequency = new int[26];

        // Iterate through the string and count the frequency of each character
        for (char c : s.toCharArray()) {
            charFrequency[c - 'a']++;
        }

        // Iterate through the string again to find the first non-repeating character
        for (int i = 0; i < s.length(); i++) {
            if (charFrequency[s.charAt(i) - 'a'] == 1) {
                return i;
            }
        }

        // If no non-repeating character is found, return -1
        return -1;
    }

    public static void main(String[] args) {
        // Test cases
        System.out.println(firstUniqChar("leetcode"));       // Output: 0
        System.out.println(firstUniqChar("loveleetcode"));    // Output: 2
        System.out.println(firstUniqChar("aabb"));            // Output: -1
    }
}
