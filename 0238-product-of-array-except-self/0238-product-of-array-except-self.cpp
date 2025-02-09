class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) 
    {
        int idx1=-1;
        int idx2=-1;
        vector<int>ans(nums.size(),0);
        int k=1;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==0)
            {
                if(idx1==-1)
                {
                    idx1=i;
                }
                else
                {
                    return ans;
                }
            }
            else
            {
                k=k*nums[i];
            }
        }

        if(idx1!=-1)
        {
            ans[idx1]=k;
            return ans;
        }
        else
        {
            for(int i=0;i<nums.size();i++)
            {
                ans[i]=k/nums[i];
            }
        }
        return ans;
    }
};