class Solution {
public:
    int Func(int i, int Buy, int Sell, vector<int>& prices, bool canBuy, vector<vector<vector<int>>>& dp) 
    {
        if (i >= prices.size()) 
        {
            return 0;
        }
        if (dp[i][Buy][canBuy] != -1)
        {
            return dp[i][Buy][canBuy];
        }

        int hold = Func(i + 1, Buy, Sell, prices, canBuy, dp); // Hold: Skip transaction

        int buy = 0, sell = 0;
        if (canBuy && Buy > 0) // Buy condition
        {
            buy = Func(i + 1, Buy - 1, Sell, prices, false, dp) - prices[i];
        }

        if (!canBuy && Sell > Buy) // Sell condition
        {
            sell = Func(i + 1, Buy, Sell - 1, prices, true, dp) + prices[i];
        }

        return dp[i][Buy][canBuy] = max({hold, buy, sell});
    }

    int maxProfit(int k, vector<int>& prices) 
    {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(k + 1, vector<int>(2, -1))); // Fix DP size
        return Func(0, k, k, prices, true, dp);
    }
};
