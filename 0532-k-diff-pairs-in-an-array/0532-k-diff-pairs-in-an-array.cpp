class Solution {
public:
    int findPairs(vector<int>& nums, int k) 
    {
        if (k < 0) return 0;

        multiset<int> mst(nums.begin(), nums.end());
        set<pair<int, int>> st;

        for (int num : nums) 
        {
            mst.erase(mst.find(num));

            if (mst.find(num + k) != mst.end()) 
            {
                st.insert({num, num + k});
            }

            if (mst.find(num - k) != mst.end()) 
            {
                st.insert({num - k, num});
            }

            mst.insert(num);  
        }

        return st.size();
    }
};
