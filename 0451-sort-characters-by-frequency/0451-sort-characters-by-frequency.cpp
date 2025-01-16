class Solution {
    static bool comparator(pair<char,int> p1, pair<char,int> p2) 
    {
        if(p1.second < p2.second)
        {
            return false;
        }
        if(p1.second > p2.second)
        {
            return true;
        }

        return p1.first > p2.first;
    }
public:
    string frequencySort(string s) 
    {
        unordered_map<char, int> freq;
        for (char ch : s) 
        {
            freq[ch]++;
        }
        vector<pair<char,int>> freqVec;
        for (auto &entry : freq) 
        {
            freqVec.push_back({entry.first, entry.second});
        }

        sort(freqVec.begin(), freqVec.end(), comparator);
        string ans;
        for (auto &entry : freqVec) 
        {
            ans.append(entry.second, entry.first);
        }
        return ans;
    }
};