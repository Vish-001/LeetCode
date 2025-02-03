class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) 
    {
        int ans=0;
        int temp=0;
        for(int i=0;i<nums.size()-1;i++)
        {
            if(nums[i]>nums[i+1])
            {
                temp++;
                ans=max(ans,temp);
            }
            else
            {
                temp=0;
            }
        }
        temp=0;
        for(int i=0;i<nums.size()-1;i++)
        {
            if(nums[i]<nums[i+1])
            {
                temp++;
                ans=max(ans,temp);
            }
            else
            {
                temp=0;
            }
        }
        return ans+1;
    }
};