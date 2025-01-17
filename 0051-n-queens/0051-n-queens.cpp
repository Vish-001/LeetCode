class Solution {
public:

    bool isSafe(int row,int col,int n,vector<string>board)
    {
        int duprow=row;
        int dupcol=col;
        // checking for row
        while(dupcol>=0)
        {
            if(board[row][dupcol]=='Q')
            {
                return false;
            }
            dupcol--;
        }
        dupcol=col;

        // checking for udigonal
        while(dupcol>=0 && duprow>=0)
        {
            if(board[duprow][dupcol]=='Q')
            {
                return false;
            }
            dupcol--;
            duprow--;
        }
        duprow=row;
        dupcol=col;

        // checking for ddigonal
        while(duprow<n && dupcol>=0)
        {
            if(board[duprow][dupcol]=='Q')
            {
                return false;
            }
            duprow++;
            dupcol--;

        }

        return true;
    }

    void Solve(int col,vector<string>board,vector<vector<string>>&ans,int n)
    {
        if(col==n)
        {
            ans.push_back(board);
            return;
        }
        for(int row=0;row<n;row++)
        {
            if(isSafe(row,col,n,board))
            {
                board[row][col]='Q';
                Solve(col+1,board,ans,n);
                board[row][col]='.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) 
    {
        vector<vector<string>>ans;
        vector<string>board(n);
        string s(n,'.');
        for(int i=0;i<n;i++)
        {
            board[i]=s;
        }
        Solve(0,board,ans,n);
        return ans;
    }
};