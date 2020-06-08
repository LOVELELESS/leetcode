class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n == 0) {
            return 0;
        }
        vector<int> dp(n, 0);
        int currMax = prices[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            int currProf = currMax - prices[i];
            dp[i] = max(dp[i + 1], currProf);
            currMax = max(prices[i], currMax);
        }
        return dp[0];
    }
};
