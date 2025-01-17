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
        for(int j=i;j<candidates.size();j++)
        {
            if(j>i && candidates[j-1]==candidates[j]) continue;
            if(target-candidates[j]>=0)
            {
                ds.push_back(candidates[j]);
                Func(j+1,target-candidates[j],ds,candidates,ans);
                ds.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) 
    {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>>ans;
        vector<int>ds;
        Func(0,target,ds,candidates,ans);
        return ans;
    }
};