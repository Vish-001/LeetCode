class Solution {
public:
    void Pse(const vector<int>& heights, vector<int>& PseArr) 
    {
        stack<int> st;
        for (int i = 0; i < heights.size(); i++) 
        {
            while (!st.empty() && heights[st.top()] >= heights[i]) 
            {
                st.pop();
            }
            PseArr[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
    }
    
    void Nse(const vector<int>& heights, vector<int>& NseArr) 
    {
        stack<int> st;
        int n = heights.size();
        for (int i = n - 1; i >= 0; i--) 
        {
            while (!st.empty() && heights[st.top()] >= heights[i]) 
            {
                st.pop();
            }
            NseArr[i] = st.empty() ? n : st.top();
            st.push(i);
        }
    }
    
    int largestRectangleArea(vector<int>& heights) 
    {
        int n = heights.size();
        vector<int> PseArr(n, -1);
        vector<int> NseArr(n, n);
        
        Pse(heights, PseArr);
        Nse(heights, NseArr);
        
        int ans = 0;
        for (int i = 0; i < n; i++) 
        {
            int width = NseArr[i] - PseArr[i] - 1;
            int area = heights[i] * width;
            ans = max(ans, area);
        }
        return ans;
    }
};
