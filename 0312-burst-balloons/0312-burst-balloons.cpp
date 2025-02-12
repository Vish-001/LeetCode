class Solution {
public:
    int Func(vector<int>& nums, int left, int right, vector<vector<int>>& dp) {
        if (left > right) return 0;
        
        if (dp[left][right] != -1) return dp[left][right]; // Return cached result

        int maxi = 0;
        for (int i = left; i <= right; i++) {
            int coins = (nums[left - 1] * nums[i] * nums[right + 1]) 
                        + Func(nums, left, i - 1, dp) 
                        + Func(nums, i + 1, right, dp);
            maxi = max(maxi, coins);
        }

        return dp[left][right] = maxi; 
    }

    int maxCoins(vector<int>& nums) 
    {
        nums.insert(nums.begin(), 1); 
        nums.push_back(1); 
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return Func(nums, 1, n - 2, dp); 
    }
};
