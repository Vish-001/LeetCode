class Solution {
public:
    int longestOnes(vector<int>& nums, int k) 
    {
        int l=0;
        int r=0;
        int ans=0;
        int zero=0;
        int mrz=0;
        while(r<nums.size())
        {
            if(nums[r]==0)
            {
                zero++;
            }
            if(zero>k)
            {
                while(nums[l]!=0)
                {
                    l++;
                }
                l++;
                zero--;
            }
            r++;
            ans=max(ans,r-l);
        }
        return ans;
    }
};