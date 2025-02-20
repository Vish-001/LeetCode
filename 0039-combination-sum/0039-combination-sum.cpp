class Solution {
public:
    void Func(int i,vector<int>ds,int target,vector<int>&candidates,vector<vector<int>>&ans)
    {
        if(target==0)
        {
            ans.push_back(ds);
            return;
        }
        if (target < 0 || i >= candidates.size()) 
        {
            return;
        }
        if(target-candidates[i]>=0)
        {
            ds.push_back(candidates[i]);
            Func(i,ds,target-candidates[i],candidates,ans);
            ds.pop_back();
        }
        Func(i+1,ds,target,candidates,ans);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) 
    {
        vector<vector<int>>ans;
        vector<int>ds;
        Func(0,ds,target,candidates,ans);
        return ans;
    }
};