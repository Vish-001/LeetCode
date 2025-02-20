class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> last(256, -1);  // Last seen positions for each character.
        int start = 0;             // Start index of current substring.
        int maxLen = 0;
        
        for (int i = 0; i < s.size(); i++) {
            // If the character has been seen and is in the current window,
            // move the start to one position after its last occurrence.
            if (last[s[i]] >= start) {
                start = last[s[i]] + 1;
            }
            last[s[i]] = i;
            maxLen = max(maxLen, i - start + 1);
        }
        
        return maxLen;
    }
};
