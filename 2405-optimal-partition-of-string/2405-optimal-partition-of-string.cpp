class Solution {
public:
    int partitionString(string s) 
    {
        unordered_set<char>st;
        int ans=1;
        for(auto c:s)
        {
            if(st.find(c)==st.end())
            {
                st.insert(c);
            }
            else
            {
                st.clear();
                st.insert(c);
                ans++;
            }
        }
        return ans;
    }
};