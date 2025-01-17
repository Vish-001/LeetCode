class Solution {
public:
    void Func(int col, vector<string>& board, vector<int>& rowHash, vector<int>& upperDiag, vector<int>& lowerDiag, int n, vector<vector<string>>& ans) {
        if (col == n) {
            ans.push_back(board);
            return;
        }

        for (int row = 0; row < n; row++) {
            if (rowHash[row] == 0 && upperDiag[row + col] == 0 && lowerDiag[(n - 1) + (row - col)] == 0) {
                // Place the queen
                rowHash[row] = 1;
                upperDiag[row + col] = 1;
                lowerDiag[(n - 1) + (row - col)] = 1;
                board[row][col] = 'Q';

                // Recur to the next column
                Func(col + 1, board, rowHash, upperDiag, lowerDiag, n, ans);

                // Backtrack
                rowHash[row] = 0;
                upperDiag[row + col] = 0;
                lowerDiag[(n - 1) + (row - col)] = 0;
                board[row][col] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n, string(n, '.')); // Initialize an empty board
        vector<int> rowHash(n, 0);               // Hash to track rows
        vector<int> upperDiag(2 * n - 1, 0);     // Hash to track upper diagonals
        vector<int> lowerDiag(2 * n - 1, 0);     // Hash to track lower diagonals

        Func(0, board, rowHash, upperDiag, lowerDiag, n, ans);
        return ans;
    }
};
