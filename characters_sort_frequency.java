// Given a string s, sort it in decreasing order based on the frequency of the characters. The frequency of a character is the number of times it appears in the string.
// Return the sorted string. If there are multiple answers, return any of them.


import java.util.*;

public class Solution {

    public static String frequencySort(String s) {
        if (s == null || s.length() <= 1) {
            return s;
        }

        // Count the frequency of each character
        Map<Character, Integer> frequencyMap = new HashMap<>();
        for (char c : s.toCharArray()) {
            frequencyMap.put(c, frequencyMap.getOrDefault(c, 0) + 1);
        }

        // Create a priority queue to sort characters based on frequency
        PriorityQueue<Character> maxHeap = new PriorityQueue<>((a, b) -> frequencyMap.get(b) - frequencyMap.get(a));

        // Add all characters to the priority queue
        maxHeap.addAll(frequencyMap.keySet());

        // Build the sorted string
        StringBuilder result = new StringBuilder();
        while (!maxHeap.isEmpty()) {
            char currentChar = maxHeap.poll();
            for (int i = 0; i < frequencyMap.get(currentChar); i++) {
                result.append(currentChar);
            }
        }

        return result.toString();
    }

    public static void main(String[] args) {
        String input = "tree";
        String result = frequencySort(input);
        System.out.println("Input: " + input);
        System.out.println("Sorted String: " + result);
    }
}
