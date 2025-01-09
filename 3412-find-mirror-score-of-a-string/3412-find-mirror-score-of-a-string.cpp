class Solution {
public:
        long long calculateScore(string s) {
        vector<vector<int>> seen(26);
        long long res = 0;
        for (int i = 0; i < s.size(); ++i) {
            int a = s[i] - 'a';
            if (seen[25 - a].empty()) {
                seen[a].push_back(i);
            } else {
                int j = seen[25 - a].back();
                seen[25 - a].pop_back();
                res += i - j;
            }
        }
        return res;
    }
};