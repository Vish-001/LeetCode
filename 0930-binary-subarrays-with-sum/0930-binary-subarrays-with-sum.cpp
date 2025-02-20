class Solution {
public:
    int Func(vector<int>& nums, int goal)
    {
        int ans=0;
        int l=0;
        int r=0;
        int sum=0;
        while(r<nums.size())
        {
            sum+=nums[r];
            while(l<=r && sum>goal)
            {
                sum-=nums[l];
                l++;
            }
            ans+=(r-l)+1;
            r++;
        }
        return ans;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) 
    {
        return Func(nums,goal)-Func(nums,goal-1);
    }
};