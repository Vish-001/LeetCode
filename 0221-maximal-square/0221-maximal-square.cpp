class Solution {
public:
    int Func(vector<int>& heights, int ans) 
    {
    stack<int> st;
    int n = heights.size();

    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && heights[i] < heights[st.top()])
        {
            int element = heights[st.top()];
            st.pop();
            int pse = st.empty() ? -1 : st.top();
            int width = i - pse - 1;
            int side = min(element, width);  // Side length of the largest square
            ans = max(ans, side * side);    // Compare max square area
        }
        st.push(i);
    }

    while (!st.empty())
    {
        int element = heights[st.top()];
        st.pop();
        int pse = st.empty() ? -1 : st.top();
        int width = n - pse - 1;
        int side = min(element, width);
        ans = max(ans, side * side);
    }
    return ans;
}

    int maximalSquare(vector<vector<char>>& matrix) 
    {
        if (matrix.empty()) return 0;

        int r = matrix.size();
        int c = matrix[0].size();
        vector<vector<int>> mat(r, vector<int>(c, 0));

        for (int i = 0; i < c; i++)
        {
            int sum = 0;
            for (int j = 0; j < r; j++)
            {
                if (matrix[j][i] == '1')
                {
                    sum++;
                }
                else
                {
                    sum = 0;
                }
                mat[j][i] = sum;
            }
        }

        int maxAra = 0;
        for (int i = 0; i < r; i++)
        {
            maxAra = max(Func(mat[i], 0), maxAra);
        }
        return maxAra;

    }
};