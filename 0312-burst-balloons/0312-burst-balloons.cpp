class Solution {
public:
    vector<vector<int>> dp;  // Memoization table

    int Func(int left, int right, vector<int>& nums) {
        if (left > right) return 0; // No balloons to burst

        if (dp[left][right] != -1) return dp[left][right];

        int maxi = 0;
        for (int i = left; i <= right; i++) {  
            int coin = nums[i] * (left > 0 ? nums[left - 1] : 1) * (right < nums.size() - 1 ? nums[right + 1] : 1);

            int remaining = Func(left, i - 1, nums) + Func(i + 1, right, nums);
            
            maxi = max(maxi, coin + remaining);
        }

        return dp[left][right] = maxi;
    }

    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        nums.insert(nums.begin(), 1); // Virtual balloon at start
        nums.push_back(1); // Virtual balloon at end

        dp.assign(n + 2, vector<int>(n + 2, -1)); // Initialize DP table
        return Func(1, n, nums); // Solve for full range
    }
};
