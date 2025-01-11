class Solution {
public:
    bool isPalindrome(string s) 
    {
        int i = 0, j = s.size() - 1;
        while (i < j) 
        {
            if (s[i] != s[j]) 
            {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }

    bool canConstruct(string s, int k) 
    {
        if (k > s.size()) return false;

        unordered_map<char, int> freq;
        for (char c : s) 
        {
            freq[c]++;
        }

        int oddCount = 0;
        for (auto& [ch, count] : freq) 
        {
            if (count % 2 != 0) 
            {
                oddCount++;
            }
        }

        return oddCount <= k;
    }
};
