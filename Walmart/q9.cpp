// Question: Guess Number Higher or Lower II
// Question Link: https://leetcode.com/problems/guess-number-higher-or-lower-ii/

class Solution {
public:
    int solve(int begin, int end, vector<vector<int>>&dp)
    {
        if(begin > end)
            return 0;
        if(dp[begin][end] > -1)
            return dp[begin][end];
        if(begin == end)
            return dp[begin][end] = 0;
        if(begin+1 == end)
        {
            return dp[begin][end] = min(begin, end);
        }
        dp[begin][end] = INT_MAX;
        for(int i=begin; i<=end; ++i)
        {
            int temp = i + max(solve(begin, i-1, dp), solve(i+1, end, dp));
            dp[begin][end] = min(dp[begin][end], temp);
        }
        return dp[begin][end];
    }
    int getMoneyAmount(int n) {
        vector<vector<int>>dp(n+1, vector<int>(n+1, -1));
        int ans = solve(1, n, dp);
        return ans;
    }
};
