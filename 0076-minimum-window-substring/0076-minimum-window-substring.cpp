class Solution {
public:
    // Helper function to check if the frequency map in the current window 
    // satisfies the requirements in targetFreq.
    bool isValid(const unordered_map<char, int>& windowFreq, 
                 const unordered_map<char, int>& targetFreq) {
        for (auto &p : targetFreq) {
            if (windowFreq.find(p.first) == windowFreq.end() || windowFreq.at(p.first) < p.second)
                return false;
        }
        return true;
    }
    
    // Check if there's any substring of s with length 'size' that contains all characters of t.
    // If found, assign that substring to ans and return true.
    bool Chk(const string &s, const string &t, int size, string &ans) {
        if (size < t.size()) return false; // Window too small to contain t

        // Build frequency map for t.
        unordered_map<char, int> targetFreq;
        for (char c : t) {
            targetFreq[c]++;
        }
        
        // Build frequency map for the first window of size 'size'
        unordered_map<char, int> windowFreq;
        for (int i = 0; i < size; i++) {
            windowFreq[s[i]]++;
        }
        
        // Check the first window.
        if (isValid(windowFreq, targetFreq)) {
            ans = s.substr(0, size);
            return true;
        }
        
        // Slide the window: remove the leftmost char and add the new rightmost char.
        for (int i = 1; i <= s.size() - size; i++) {
            windowFreq[s[i - 1]]--;
            windowFreq[s[i + size - 1]]++;
            if (isValid(windowFreq, targetFreq)) {
                ans = s.substr(i, size);
                return true;
            }
        }
        return false;
    }
    
    string minWindow(string s, string t) {
        int n = s.size();
        if (t.size() > n) return "";
        
        int low = t.size(), high = n;
        string ans = "";
        string result = "";
        bool found = false;
        
        // Binary search for the smallest window length that contains t.
        while (low <= high) {
            int mid = (low + high) / 2;
            string candidate = "";
            if (Chk(s, t, mid, candidate)) {
                found = true;
                result = candidate;  // record this valid window
                high = mid - 1;      // try to find a smaller valid window
            } else {
                low = mid + 1;       // no valid window of length mid, so increase size
            }
        }
        return found ? result : "";
    }
};
