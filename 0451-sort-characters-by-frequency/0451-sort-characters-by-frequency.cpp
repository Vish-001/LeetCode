class Solution {
public:
    string frequencySort(string s) {
        map<char, int> mp;
        for (auto c : s) 
        {
            mp[c]++;
        }

        vector<pair<char, int>> pairs(mp.begin(), mp.end());

        sort(pairs.begin(), pairs.end(), [](const auto& a, const auto& b) 
        {
            return a.second > b.second;
        });

        string result = "";
        for (const auto& p : pairs) 
        {
            int k = p.second;
            for (int i = 0; i < k; i++) 
            {
                result += p.first;
            }
        }

        return result;
    }
};
