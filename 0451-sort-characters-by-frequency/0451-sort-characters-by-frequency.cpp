class Solution {
public:
    string frequencySort(string s) 
    {
        unordered_map<char, int> mp;
        for (char c : s) {
            mp[c]++;
        }

        priority_queue<pair<int, char>> pq;

        for (auto& p : mp) {
            pq.push({p.second, p.first});  // Frequency first, character second
        }

        string ans;
        while (!pq.empty()) {
            auto [freq, c] = pq.top();
            pq.pop();
            ans.append(freq, c);  // Append 'freq' times
        }

        return ans;
    }
};
