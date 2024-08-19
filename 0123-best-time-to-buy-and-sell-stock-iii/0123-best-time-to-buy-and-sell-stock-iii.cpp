class Solution {
public:
    int f(int i, int limit, int buy, vector<int>& prices, vector<vector<vector<int>>>& dp, int n) { 
        if (i == prices.size()) return 0;
        if (limit == 0) return 0;

        if (dp[i][limit][buy] != -1) return dp[i][limit][buy];
        int profit = 0;
        if (buy == 1) {
            profit = max(f(i + 1, limit, 0, prices, dp, n) - prices[i],
                         f(i + 1, limit, 1, prices, dp, n));
        } else {
            profit = max(f(i + 1, limit - 1, 1, prices, dp, n) + prices[i],
                         f(i + 1, limit, 0, prices, dp, n));
        }

        return dp[i][limit][buy] = profit;
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(3, vector<int>(2, -1))); 
        return f(0, 2, 1, prices, dp, n);
    }
};
