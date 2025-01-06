class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) 
    {
        int n = mat.size();
        int m = mat[0].size();
        vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        queue<pair<int, int>> q;

        for (int i = 0; i < n; i++) 
        {
            for (int j = 0; j < m; j++) 
            {
                if (mat[i][j] == 0) 
                {
                    q.push({i, j});
                } 
                else 
                {
                    mat[i][j] = INT_MAX;
                }
            }
        }

        while (!q.empty()) 
        {
            auto cell = q.front();
            q.pop();
            int row = cell.first;
            int col = cell.second;

            for (pair<int, int> direction : directions) 
            {
                int nr = row + direction.first;
                int nc = col + direction.second;

                if (nr >= 0 && nr < n && nc >= 0 && nc < m && mat[nr][nc] > mat[row][col] + 1) {
                    mat[nr][nc] = mat[row][col] + 1;
                    q.push({nr, nc});
                }
            }
        }

        return mat;        
    }
};