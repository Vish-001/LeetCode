#include <unordered_set>
#include <string>
#include <vector>

class Solution {
public:
    bool Search(int start, int end, string s, unordered_set<string>& st, vector<int>& dp) {
        if (start == s.size()) {
            return true;
        }

        if (end > s.size()) {
            return false;
        }

        if (dp[start] != -1) {
            return dp[start];
        }

        string word = s.substr(start, end - start);

        if (st.find(word) != st.end()) 
        {
            if (Search(end, end + 1, s, st, dp)) 
            {
                return dp[start] = true;
            }
        }

        return dp[start] = Search(start, end + 1, s, st, dp);
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> st(wordDict.begin(), wordDict.end());
        vector<int> dp(s.size(), -1);  // Memoization array

        return Search(0, 0, s, st, dp);
    }
};
