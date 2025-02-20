class Solution {
public:
    void Func(int i,vector<int>ds,vector<int>&nums,vector<vector<int>>&ans)
    {
        if(i==nums.size())
        {
            ans.push_back(ds);
            return;
        }
        ds.push_back(nums[i]);
        Func(i+1,ds,nums,ans);
        ds.pop_back();
        Func(i+1,ds,nums,ans);
    }
    
    vector<vector<int>> subsets(vector<int>& nums) 
    {
        vector<vector<int>>ans;
        vector<int>ds;
        Func(0,ds,nums,ans);
        return ans;
    }
};