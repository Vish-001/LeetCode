class Solution {
public:
    void Pse(vector<int>& ans, vector<int>& arr) {
        stack<int> st;
        for (int i = 0; i < arr.size(); i++) {
            while (!st.empty() && arr[st.top()] > arr[i]) {
                st.pop();
            }
            if (!st.empty()) {
                ans[i] = st.top();
            }
            st.push(i);
        }
    }

    void Nse(vector<int>& ans, vector<int>& arr) {
        stack<int> st;
        for (int i = arr.size() - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] >= arr[i]) { // Use `>=` for next smaller or equal.
                st.pop();
            }
            if (!st.empty()) {
                ans[i] = st.top();
            }
            st.push(i);
        }
    }

    int sumSubarrayMins(vector<int>& arr) {
        int mod = 1e9 + 7; // Correct modulo value
        int n = arr.size();
        
        vector<int> Psee(n, -1); // Previous smaller elements
        Pse(Psee, arr);
        
        vector<int> Nsee(n, n); // Next smaller elements
        Nse(Nsee, arr);

        long long ans = 0;
        for (int i = 0; i < n; i++) {
            int k = i - Psee[i];     // Distance to previous smaller
            int l = Nsee[i] - i;    // Distance to next smaller
            ans = (ans + (1LL * k * l % mod) * arr[i] % mod) % mod; // Compute contribution
        }
        return ans;
    }
};
