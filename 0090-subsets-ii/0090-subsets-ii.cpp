class Solution {
public:
    void Func(int i,vector<int>ds,vector<int>&nums,vector<vector<int>>&ans)
    {
        if(i>nums.size())
        {
            return;
        }
        ans.push_back(ds);
        for(int j=i;j<nums.size();j++)
        {
            if(j>i && nums[j]==nums[j-1]) continue;
            ds.push_back(nums[j]);
            Func(j+1,ds,nums,ans);
            ds.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) 
    {
        vector<vector<int>>ans;
        vector<int>ds;
        sort(nums.begin(),nums.end());
        Func(0,ds,nums,ans);
        return ans;   
    }
};