class Solution {
public:
    void Func(int col, vector<string>& board, vector<int>& rowHash, vector<int>& upperDiag, vector<int>& lowerDiag, int n, vector<vector<string>>& ans) 
    {
        if (col == n) 
        {
            ans.push_back(board);
            return;
        }

        for (int row = 0; row < n; row++) 
        {
            if (rowHash[row] == 0 && upperDiag[row + col] == 0 && 
            lowerDiag[(n - 1) + (row - col)] == 0) 
            {
                rowHash[row] = 1;
                upperDiag[row + col] = 1;
                lowerDiag[(row+n)-col-1] = 1;
                board[row][col] = 'Q';

                Func(col + 1, board, rowHash, upperDiag, lowerDiag, n, ans);

                rowHash[row] = 0;
                upperDiag[row + col] = 0;
                lowerDiag[(row+n)-col-1] = 0;
                board[row][col] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) 
    {
        vector<vector<string>> ans;
        vector<string> board(n, string(n, '.')); 
        vector<int> rowHash(n, 0);              
        vector<int> upperDiag(2 * n - 1, 0);     
        vector<int> lowerDiag(2 * n - 1, 0);     

        Func(0, board, rowHash, upperDiag, lowerDiag, n, ans);
        return ans;
    }
};
