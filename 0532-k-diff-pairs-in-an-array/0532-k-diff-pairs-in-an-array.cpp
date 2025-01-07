class Solution {
public:
    int findPairs(vector<int>& nums, int k) 
    {
        if (k < 0) return 0; // No valid pairs if k is negative

        unordered_map<int, int> freq;
        int ans = 0;

        // Count the frequency of each number
        for (int num : nums) {
            freq[num]++;
        }

        // Check for pairs
        for (auto& [num, count] : freq) {
            if (k == 0) {
                // Special case: k = 0, count pairs with duplicates
                if (count > 1) {
                    ans++;
                }
            } else {
                // General case: Check for `num + k`
                if (freq.count(num + k)) {
                    ans++;
                }
            }
        }

        return ans;
    }
};
