class Solution {
public:
    bool canJump(vector<int>& nums) 
    {
        if(nums[0]==0 && nums.size()<=1) return true;
        int mxidx=0;
        for(int i=0;i<nums.size();i++)
        {
            if(i>mxidx) return false;
            mxidx=max(mxidx,nums[i]+i);
        }
        if(mxidx>=nums.size()-1)
        {
            return true;
        }
        return false;
    }
};