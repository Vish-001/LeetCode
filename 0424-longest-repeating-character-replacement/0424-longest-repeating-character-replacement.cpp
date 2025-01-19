class Solution {
public:
    int characterReplacement(string s, int k) {
        int r = 0, l = 0, ans = 0, mf = 0;
        unordered_map<char, int> mp;

        while (r < s.size()) {
            // Add the current character to the window
            mp[s[r]]++;
            mf = max(mf, mp[s[r]]); // Update the max frequency in the window

            // If the current window is invalid (too many replacements needed)
            while ((r - l + 1) - mf > k) {
                mp[s[l]]--; // Shrink the window from the left
                l++;
            }

            // Update the answer with the current valid window size
            ans = max(ans, r - l + 1);

            r++; // Expand the window to the right
        }

        return ans;
    }
};
