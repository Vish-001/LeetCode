class Solution {
public:
    void dfs(int r, int c, vector<vector<int>>& vis, vector<vector<int>>& grid, int &temp) {
        vis[r][c] = 1;
        temp++; // Count current cell

        int dr[4] = {0, 1, -1, 0};
        int dc[4] = {1, 0, 0, -1};

        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if (nr >= 0 && nr < grid.size() && nc >= 0 && nc < grid[0].size() &&
                vis[nr][nc] == 0 && grid[nr][nc] == 1) {
                dfs(nr, nc, vis, grid, temp);
            }
        }
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans = 0;
        vector<vector<int>> vis(grid.size(), vector<int>(grid[0].size(), 0));

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1 && vis[i][j] == 0) {
                    int temp = 0;  // Initialize new island size
                    dfs(i, j, vis, grid, temp);
                    ans = max(ans, temp); // Update max area
                }
            }
        }
        return ans;
    }
};
