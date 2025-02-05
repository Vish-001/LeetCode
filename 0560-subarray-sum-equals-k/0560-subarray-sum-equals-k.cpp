class Solution {
public:
    int subarraySum(vector<int>& nums, int k) 
    {
        unordered_map<int,int>mp;
        mp[0]++;
        int sum=0;
        int cnt=0;
        for(auto c:nums)
        {
            sum+=c;
            int t=sum-k;
            if(mp.find(t)!=mp.end())
            {
                cnt+=mp[t];
            }
            mp[sum]++;
        }
        return cnt;
    }
};