class Solution {
public:
    int maxArea(vector<int>& height) 
    {
        int ans=0;
        int l=0;
        int r=height.size()-1;
        while(l<r)
        {
            if(height[l]>height[r])
            {
                int water=height[r]*(r-l);
                r--;
                ans=max(water,ans);
            }
            else
            {
                int water=height[l]*(r-l);
                l++;
                ans=max(water,ans);
            }
        }
        return ans;
    }
};