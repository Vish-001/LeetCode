class Solution {
public:
    int minimumOperations(vector<int>& nums) 
    {
        set<int>st;
        for(auto c:nums)
        {
            if(c!=0)
            {
                st.insert(c);
            }
        }
        return st.size();
    }
};