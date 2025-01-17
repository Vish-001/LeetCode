class Solution {
public:
    void Func(int i,int target,vector<int>ds,vector<int>& candidates,vector<vector<int>>&ans)
    {
        if(target==0)
        {
            ans.push_back(ds);
            return;
        }
        if(i==candidates.size())
        {
            return;
        }
        if(target-candidates[i]>=0)
        {
            ds.push_back(candidates[i]);
            Func(i,target-candidates[i],ds,candidates,ans);
            ds.pop_back();
        }
        Func(i+1,target,ds,candidates,ans);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) 
    {
        vector<vector<int>>ans;
        vector<int>ds;
        Func(0,target,ds,candidates,ans);
        return ans;
    }
};