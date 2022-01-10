// Question: Maximum Profit
// Question Link: https://practice.geeksforgeeks.org/problems/maximum-profit4657/1
class Solution {
  public:
    int maxProfit(int k, int n, int prices[]) {
        if(n==0 || n==1)
            return 0;
        int dp[k+1][n];
        
        for(int i=0; i<n; ++i)
            dp[0][i] = 0;
        for(int i=0; i<=k; ++i)
            dp[i][0] = 0;
        
        int maxDiff;
        for(int i=1; i<=k; ++i)
        {
            maxDiff = dp[i-1][0] - prices[0];
            for(int j=1; j<n; ++j)
            {
                dp[i][j] = max(dp[i][j-1], prices[j]+maxDiff);
                maxDiff = max(maxDiff, dp[i-1][j] - prices[j]);
            }
        }
        int ans = 0;
        for(int i=0; i<=k; ++i)
            ans = max(ans, dp[i][n-1]);
        return ans;
    }
};
