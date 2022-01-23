// Question: Pots of Gold Game 
// Question Link: https://practice.geeksforgeeks.org/problems/pots-of-gold-game/1/

class Solution {
public:
    int solve(int begin, int end, vector<int>&a, vector<vector<int>>&dp)
    {
        if(end == begin)
            return a[end];
        if(end == begin+1)
        {
            dp[begin][end] = max(a[begin], a[end]);
            return dp[begin][end];
        }
        if(dp[begin][end] >= 0)
            return dp[begin][end];
        int first = a[begin] + min(solve(begin+2, end, a, dp), solve(begin+1, end-1, a, dp));
        int last = a[end] + min(solve(begin, end-2, a, dp), solve(begin+1, end-1, a, dp));
        return dp[begin][end] = max(last, first);
    }
    int maxCoins(vector<int>&a,int n)
    {
	    //Write your code here
	    vector<vector<int>>dp(n, vector<int>(n,-1));
	    int total = 0;
	    for(auto i:a)
	        total += i;
	    int ans = solve(0, n-1, a, dp);
	    return ans;
    }
};
