class Solution {
    static bool comparator(pair<int, char> p1, pair<int, char> p2) {
        if (p1.first > p2.first) {
            return true;
        }
        if (p1.first < p2.first) {
            return false;
        }
        return p1.second < p2.second;
    }
public:
    string frequencySort(string s) {
        unordered_map<char, int> freq;
        for (char ch : s) {
            freq[ch]++;
        }
        vector<pair<int, char>> freqVec;
        for (auto &entry : freq) {
            freqVec.push_back({entry.second, entry.first});
        }
        sort(freqVec.begin(), freqVec.end(), comparator);
        string ans;
        for (auto &entry : freqVec) {
            ans.append(entry.first, entry.second);
        }
        return ans;
    }
};