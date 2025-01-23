class Solution {
public:
    int jump(vector<int>& nums) 
    {
        if(nums.size()<=1) return 0;
        int l=0;
        int r=0;
        int jump=0;
        while(r<nums.size()-1)
        {
            int far=0;
            for(int i=l;i<=r;i++)
            {
                far=max(far,nums[i]+i);
            }
            l=r+1;
            r=far;
            jump++;
        }
        return jump;
    }
};