class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        priority_queue<pair<int, char>> q;
        unordered_map<char, int> mp;
        for (char c : tasks) {
            mp[c]++;
        }
        for (auto it : mp) {
            q.push({it.second, it.first});
        }
        pair<int, char> temp;
        vector<pair<int, char>> vt;
        int ans = 0;
        int i = 0;
        int qsiz = q.size();
        while (!q.empty()) {
            qsiz = q.size();
            while (i < min(n + 1, qsiz)) {
                vt.push_back({q.top().first, q.top().second});
                q.pop();
                i++;
            }
            i = 0;
            for (pair<int, char> x : vt) {
                if (x.first > 1) {
                    q.push({x.first - 1, x.second});
                }
            }

            if (q.empty()) {
                //cout << vt.size() << "\n";
                ans += vt.size();
            } else {
                //cout << max(n + 1, (int)vt.size()) << "\n";
                ans += n + 1;
            }
            vt.clear();
        }
        return ans;
    }
};