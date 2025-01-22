class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;
        
        for (auto c : num) {
            while (!st.empty() && st.top() > c && k > 0) {
                st.pop();
                k--;
            }
            st.push(c);
        }
        
        // Remove remaining digits if `k > 0`
        while (k > 0 && !st.empty()) {
            st.pop();
            k--;
        }
        
        // Build the result from the stack
        string ans = "";
        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        
        // Remove leading zeros
        int idx = 0;
        while (idx < ans.size() && ans[idx] == '0') {
            idx++;
        }
        ans = ans.substr(idx);
        
        // If the result is empty, return "0"
        return ans.empty() ? "0" : ans;
    }
};
