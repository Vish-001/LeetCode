class Solution {
public:
    int findPairs(vector<int>& nums, int k) 
    {
        if (k < 0) return 0;  

        unordered_multiset<int> mst(nums.begin(), nums.end());
        set<pair<int, int>> st;  // Use `set` to avoid duplicate pairs

        for (int num : nums) 
        {
            mst.erase(mst.find(num));  // Temporarily remove the current number

            // Check for `num + k`
            if (mst.find(num + k) != mst.end()) {
                st.insert({num, num + k});  // Insert pair
            }

            // Check for `num - k`
            if (mst.find(num - k) != mst.end()) {
                st.insert({num - k, num});  // Insert pair
            }

            mst.insert(num);  // Reinsert the current number
        }

        return st.size();  // Return the number of unique pairs
    }
};
