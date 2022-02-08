// Question: Stone Game
// Question Link: https://leetcode.com/problems/stone-game/

class Solution {
public:
    int solve(int start, int end, vector<int>&piles, vector<vector<int>>&dp)
    {
        if(dp[start][end] >= 0)
            return dp[start][end];
        if(start == end)
            return dp[start][end] = piles[start];
        if(end == start+1)
            return dp[start][end] = max(piles[start], piles[end]);
        int first = piles[start] + max(solve(start+2, end, piles, dp), solve(start+1, end-1, piles, dp));
        int last = piles[end] + max(solve(start+1, end-1, piles, dp), solve(start, end-2, piles, dp));
        return dp[start][end] = max(first, last);
    }
    bool stoneGame(vector<int>& piles) {
        int total = 0, n=piles.size();
        for(auto i:piles)
            total += i;
        vector<vector<int>>dp(n, vector<int>(n, -1));
        solve(0, n-1, piles, dp);
        return (dp[0][n-1]*2 > total);
    }
};
