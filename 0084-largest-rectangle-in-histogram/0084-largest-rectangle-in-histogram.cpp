class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int ans = 0;
        stack<int> st;

        for (int i = 0; i < heights.size(); i++) 
        {
            while (!st.empty() && heights[i] < heights[st.top()]) 
            {
                int element = heights[st.top()];
                st.pop();
                
                int area;
                if (st.empty()) 
                {
                    area = i * element;
                } 
                else 
                {
                    area = element * (i- st.top() - 1);
                }
                ans = max(ans, area);
            }
            st.push(i);
        }

        while (!st.empty()) 
        {
            int element = heights[st.top()];
            st.pop();

            int area;
            if (st.empty()) 
            {
                area = heights.size() * element;
            } 
            else 
            {
                area = element * (heights.size() - st.top() - 1);
            }
            ans = max(ans, area);
        }

        return ans;
    }
};
