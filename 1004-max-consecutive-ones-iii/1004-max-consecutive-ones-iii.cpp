class Solution {
public:
    int longestOnes(vector<int>& nums, int k) 
    {
        int cnt=0;
        int l=0;
        int ans=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]!=1)
            {
                cnt++;
            }
            while(cnt>k)
            {
                if(nums[l]!=1)
                {
                    cnt--;
                }
                l++;
            }
            if(cnt<=k)
            {
                ans=max(ans,i-l+1);
            }
        }
        return ans;
    }
};