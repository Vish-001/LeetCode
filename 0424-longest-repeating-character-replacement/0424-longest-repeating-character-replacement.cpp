class Solution {
public:
    int characterReplacement(string s, int k) {
        int r = 0, l = 0, ans = 0, mf = 0;
        unordered_map<char, int> mp;

        while (r < s.size()) {
            mp[s[r]]++;
            mf = max(mf, mp[s[r]]);

            // If the current window is invalid
            while ((r - l + 1) - mf > k) {
                mp[s[l]]--;
                l++;

                // Recalculate mf in the current window
                mf = 0;
                for (auto &entry : mp) {
                    mf = max(mf, entry.second);
                }
            }

            ans = max(ans, r - l + 1);
            r++;
        }

        return ans;
    }
};
