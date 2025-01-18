#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    void Func(int row, int col, int cost, vector<vector<int>>& grid, int& ans, vector<vector<int>>& dp) {
        // Base case: If we've exceeded the current minimum cost, stop exploring
        if (cost >= ans) return;

        // Base case: If we reached the bottom-right corner, update the answer
        if (row == grid.size() - 1 && col == grid[0].size() - 1) {
            ans = min(cost, ans);
            return;
        }

        // If already visited with a smaller cost, skip further exploration
        if (dp[row][col] != -1 && dp[row][col] <= cost) {
            return;
        }

        // Update dp with the current minimum cost
        dp[row][col] = cost;

        // Mark the current cell as visited
        int originalValue = grid[row][col];
        grid[row][col] = 0;

        // Movement costs for directions [right, left, down, up]
        int u = 1, d = 1, l = 1, r = 1;
        if (originalValue == 1) r = 0;
        else if (originalValue == 2) l = 0;
        else if (originalValue == 3) d = 0;
        else u = 0;

        // Explore all four directions
        // Up
        if (row - 1 >= 0 && grid[row - 1][col] != 0) {
            Func(row - 1, col, cost + u, grid, ans, dp);
        }
        // Down
        if (row + 1 < grid.size() && grid[row + 1][col] != 0) {
            Func(row + 1, col, cost + d, grid, ans, dp);
        }
        // Left
        if (col - 1 >= 0 && grid[row][col - 1] != 0) {
            Func(row, col - 1, cost + l, grid, ans, dp);
        }
        // Right
        if (col + 1 < grid[0].size() && grid[row][col + 1] != 0) {
            Func(row, col + 1, cost + r, grid, ans, dp);
        }

        // Backtrack by restoring the cell's original value
        grid[row][col] = originalValue;
    }

    int minCost(vector<vector<int>>& grid) {
        int ans = grid.size() + grid[0].size() - 2; // Maximum possible cost
        vector<vector<int>> dp(grid.size(), vector<int>(grid[0].size(), -1)); // Initialize dp with -1
        Func(0, 0, 0, grid, ans, dp);
        return ans;
    }
};
