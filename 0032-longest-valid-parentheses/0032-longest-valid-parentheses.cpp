class Solution {
public:
    int longestValidParentheses(string s) {
        int cnt = 0;
        int l = 0, r = 0;
        int ans = 0;

        while (r < s.size()) {
            if (s[r] == '(') {
                cnt++;
            } else {
                cnt--;
            }
            r++;

            if (cnt == 0) {
                ans = max(ans, r - l);
            }

            while (l < r && cnt < 0) {
                if (s[l] == '(') {
                    cnt--; // Reduce opening count
                } else {
                    cnt++; // Reduce closing count
                }
                l++;
            }
        }

        cnt = 0; // Reset count for second pass
        l = r = s.size() - 1;

        while (l >= 0) {
            if (s[l] == ')') {
                cnt++;
            } else {
                cnt--;
            }
            l--;

            if (cnt == 0) {
                ans = max(ans, r - l);
            }

            while (r > l && cnt < 0) {
                if (s[r] == ')') {
                    cnt--;
                } else {
                    cnt++;
                }
                r--;
            }
        }

        return ans;
    }
};
