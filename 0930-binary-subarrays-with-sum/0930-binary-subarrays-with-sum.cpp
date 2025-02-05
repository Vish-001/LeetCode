class Solution {
public:
    int Func(vector<int>& nums, int goal)
    {
        if(goal<0) return 0;
        int l=0;
        int ans=0;
        int sum=0;
        for(int r=0;r<nums.size();r++)
        {
            sum+=nums[r];
            while(sum>goal)
            {
                sum-=nums[l];
                l++;
            }
            ans+=r-l+1;
        }
        return ans;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) 
    {
        return Func(nums,goal)-Func(nums,goal-1);
    }
};