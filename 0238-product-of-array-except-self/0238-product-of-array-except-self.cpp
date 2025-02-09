class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) 
    {
        vector<int>pre(nums.size(),0);
        vector<int>suff(nums.size(),0);

        int k=1;
        for(int i=0;i<nums.size();i++)
        {
            pre[i]=k;
            k*=nums[i];
        }
        k=1;
        for(int i=nums.size()-1;i>=0;i--)
        {
            suff[i]=k;
            k*=nums[i];
        }

        vector<int>ans(nums.size(),0);
        for(int i=0;i<nums.size();i++)
        {
            ans[i]=pre[i]*suff[i];
        }
        return ans;
    }
};