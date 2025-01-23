class Solution {
public:
    bool Func(int i, int open, int close, const string &s, vector<vector<vector<int>>> &dp) {
        // Check if this state has been computed before
        if (dp[i][open][close] != -1) {
            return dp[i][open][close] == 1;
        }

        // If more closing brackets than opening, invalid string
        if (close > open) {
            dp[i][open][close] = 0;
            return false;
        }
        
        // If we've processed all characters
        if (i == s.size()) {
            bool result = (open == close);
            dp[i][open][close] = result ? 1 : 0;
            return result;
        }

        bool result;
        if (s[i] == '*') {
            // '*' can be treated as '(', ')', or ignored
            result = Func(i + 1, open + 1, close, s, dp) || // as '('
                     Func(i + 1, open, close + 1, s, dp) || // as ')'
                     Func(i + 1, open, close, s, dp);       // as ''
        } else if (s[i] == '(') {
            result = Func(i + 1, open + 1, close, s, dp);
        } else { // s[i] == ')'
            result = Func(i + 1, open, close + 1, s, dp);
        }

        // Store the result in dp for future use
        dp[i][open][close] = result ? 1 : 0;
        return result;
    }

    bool checkValidString(string s) {
        // Initialize dp with -1 to indicate not computed states
        vector<vector<vector<int>>> dp(s.size() + 1, vector<vector<int>>(s.size() + 1, vector<int>(s.size() + 1, -1)));
        return Func(0, 0, 0, s, dp);
    }
};