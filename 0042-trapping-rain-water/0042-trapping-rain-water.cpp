class Solution {
public:
    int Pge(int idx, vector<int>& height) 
    {
        if (idx < 0) return -1;
        int maxi = -1;
        for (int i = 0; i <= idx; i++) 
        {
            maxi = max(height[i], maxi); 
        }
        return maxi;
    }

    int Nge(int idx, vector<int>& height) 
    {
        if (idx >= height.size()) return -1;
        int maxi = -1;
        for (int i = idx; i < height.size(); i++) 
        {
            maxi = max(height[i], maxi); 
        }
        return maxi;
    }

    int trap(vector<int>& height) 
    {
        int ans = 0;
        for (int i = 0; i < height.size(); i++) 
        {
            int Pg = Pge(i - 1, height); 
            int Ng = Nge(i + 1, height); 
            if (Pg == -1 || Ng == -1) continue;
            int mini = min(Pg, Ng);
            ans += max(0, mini - height[i]); 
        }
        return ans;
    }
};
