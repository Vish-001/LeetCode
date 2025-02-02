class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) 
    {
        priority_queue<pair<int,int>>pq;
        unordered_map<int,int>mp;
        for(auto c:nums)
        {
            mp[c]++;
        }
        for(auto it:mp)
        {
            int freq=it.first;
            int i=it.second;
            pq.push({i,freq});
        }
        vector<int>ans;
        while(!pq.empty() && k>0)
        {
            auto p=pq.top();
            pq.pop();
            ans.push_back(p.second);
            k--;
        }
        
        return ans;
    }
};