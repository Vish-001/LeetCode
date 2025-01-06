class Solution {
public:
    void dfs(int r, int c, vector<vector<char>>& board) 
    {
        int rows = board.size();
        int cols = board[0].size();

        // Directions for traversal
        int dr[] = {0, 1, 0, -1};
        int dc[] = {1, 0, -1, 0};

        board[r][c] = 'Y'; // Temporarily mark the cell as 'Y'

        for (int i = 0; i < 4; i++) 
        {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if (nr >= 0 && nr < rows && nc >= 0 && nc < cols && board[nr][nc] == 'O') 
            {
                dfs(nr, nc, board);
            }
        }
    }

    void solve(vector<vector<char>>& board) 
    {
        if (board.empty()) return;

        int rows = board.size();
        int cols = board[0].size();

        // Traverse the first and last rows
        for (int i = 0; i < cols; i++) 
        {
            if (board[0][i] == 'O') dfs(0, i, board);
            if (board[rows - 1][i] == 'O') dfs(rows - 1, i, board);
        }

        // Traverse the first and last columns
        for (int i = 0; i < rows; i++) 
        {
            if (board[i][0] == 'O') dfs(i, 0, board);
            if (board[i][cols - 1] == 'O') dfs(i, cols - 1, board);
        }

        // Final pass: convert 'O' to 'X' and 'Y' back to 'O'
        for (int i = 0; i < rows; i++) 
        {
            for (int j = 0; j < cols; j++) 
            {
                if (board[i][j] == 'O') 
                {
                    board[i][j] = 'X'; // Convert unvisited 'O' to 'X'
                } 
                else if (board[i][j] == 'Y') 
                {
                    board[i][j] = 'O';
                }
            }
        }
    }
};
