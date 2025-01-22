class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int ans = 0;
        stack<int> st;

        for (int i = 0; i < heights.size(); i++) {
            while (!st.empty() && heights[i] < heights[st.top()]) {
                int k = heights[st.top()];
                st.pop();
                
                int u;
                if (st.empty()) {
                    u = i * k;
                } else {
                    u = k * (i - st.top() - 1);
                }
                ans = max(ans, u);
            }
            st.push(i);
        }

        while (!st.empty()) {
            int k = heights[st.top()];
            st.pop();

            int u;
            if (st.empty()) {
                u = heights.size() * k;
            } else {
                u = k * (heights.size() - st.top() - 1);
            }
            ans = max(ans, u);
        }

        return ans;
    }
};
