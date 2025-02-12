class Solution {
public:
    int dp[301][301]; 
    
    int Func(vector<int>& nums, int left, int right) 
    {
        if (left > right) return 0;
        
        if (dp[left][right] != -1) return dp[left][right]; // Return cached result

        int maxi = 0;
        for (int i = left; i <= right; i++) {
            int coins = nums[left - 1] * nums[i] * nums[right + 1] 
                        + Func(nums, left, i - 1) + Func(nums, i + 1, right);
            maxi = max(maxi, coins);
        }

        return dp[left][right] = maxi; // Store result in DP table
    }

    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(), 1); // Add virtual left boundary
        nums.push_back(1); // Add virtual right boundary
        memset(dp, -1, sizeof(dp)); // Initialize DP table
        return Func(nums, 1, nums.size() - 2); // Call recursive function
    }
};
