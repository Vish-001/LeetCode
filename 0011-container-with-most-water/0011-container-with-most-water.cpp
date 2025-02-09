class Solution {
public:
    int maxArea(vector<int>& height) 
    {
        int ans=0;
        int l=0;
        int mini=INT_MIN;
        int r=height.size()-1;
        while(l<r)
        {
            if(height[l]>height[r])
            {
                if(height[r]>mini)
                {
                    int water=height[r]*(r-l);
                    ans=max(water,ans);
                    mini=height[r];
                }
                r--;
            }
            else
            {
                if(height[l]>mini)
                {
                    int water=height[l]*(r-l);
                    ans=max(water,ans);
                    mini=height[l];
                }
                l++;
            }
        }
        return ans;
    }
};