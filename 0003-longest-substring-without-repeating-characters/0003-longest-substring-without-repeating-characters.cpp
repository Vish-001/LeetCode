class Solution {
public:
    int lengthOfLongestSubstring(string s) 
    {
        int hash[256];
        for(int i=0;i<256;i++)
        {
            hash[i]=-1;
        }
        int ans = 0;
        int start = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (hash[s[i]] != -1) 
            {
                start = max(start, hash[s[i]] + 1);
            }
            // Update the answer with the current window size
            ans = max(ans, i - start + 1);
            // Update the last seen index of the current character
            hash[s[i]] = i;
        }
        return ans;
    }
};