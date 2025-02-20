class Solution {
public:
    void Func(int i, int target, vector<int>& ds, vector<int>& cd, vector<vector<int>>& ans) {
        if (target == 0) {
            ans.push_back(ds);
            return;
        }
        if (target < 0 || i >= cd.size()) {
            return;
        }
        
        // Explore including the current candidate cd[i]
        ds.push_back(cd[i]);
        Func(i, target - cd[i], ds, cd, ans);
        ds.pop_back(); // Backtrack
        
        // Explore without including the current candidate cd[i]
        Func(i + 1, target, ds, cd, ans);
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> ds;
        Func(0, target, ds, candidates, ans);
        return ans;
    }
};
