// You are given a rows x cols matrix grid representing a field of cherries where grid[i][j] represents the number of cherries that you can collect from the (i, j) cell.
// You have two robots that can collect cherries for you:
// Robot #1 is located at the top-left corner (0, 0), and
// Robot #2 is located at the top-right corner (0, cols - 1).
// Return the maximum number of cherries collection using both robots by following the rules below:
// From a cell (i, j), robots can move to cell (i + 1, j - 1), (i + 1, j), or (i + 1, j + 1).
// When any robot passes through a cell, It picks up all cherries, and the cell becomes an empty cell.
// When both robots stay in the same cell, only one takes the cherries.
// Both robots cannot move outside of the grid at any moment.
// Both robots should reach the bottom row in grid.



public class Solution {
    public int CherryPickup(int[][] grid) {
        int rows = grid.Length;
        int cols = grid[0].Length;

        // Create a 3D array to store the maximum cherries for each position and robot combination
        int[,,] dp = new int[rows, cols, cols];

        // Iterate through the rows in reverse order
        for (int i = rows - 1; i >= 0; i--) {
            for (int j1 = 0; j1 < cols; j1++) {
                for (int j2 = 0; j2 < cols; j2++) {
                    // Initialize current cell value
                    int cherries = grid[i][j1];
                    
                    // If the robots are in different columns, add cherries from the second robot
                    if (j1 != j2) {
                        cherries += grid[i][j2];
                    }

                    // If not in the last row, consider cherries collected from the next row
                    if (i != rows - 1) {
                        int maxNext = 0;

                        // Iterate through all possible next positions for both robots
                        for (int k1 = j1 - 1; k1 <= j1 + 1; k1++) {
                            for (int k2 = j2 - 1; k2 <= j2 + 1; k2++) {
                                // Check if the next positions are within the bounds of the grid
                                if (k1 >= 0 && k1 < cols && k2 >= 0 && k2 < cols) {
                                    maxNext = Math.Max(maxNext, dp[i + 1, k1, k2]);
                                }
                            }
                        }

                        cherries += maxNext;
                    }

                    // Store the result in the dp array
                    dp[i, j1, j2] = cherries;
                }
            }
        }

        // The result is stored in the top-left cell of the dp array
        return dp[0, 0, cols - 1];
    }
}
