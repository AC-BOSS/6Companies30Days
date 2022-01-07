// Question: Count ways to N'th Stair(Order does not matter)
// Question Link: https://practice.geeksforgeeks.org/problems/count-ways-to-nth-stairorder-does-not-matter1322/1/

#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    //Function to count number of ways to reach the nth stair 
    //when order does not matter.
    long long solve(int ind, int m, vector<vector<int>>&dp)
    {
        if(m < 0)
            return 0;
        if(m == 0)
        {
            dp[ind][m] = 1;
            return 1;
        }
        if(dp[ind][m] >= 0)
            return dp[ind][m];
            
        dp[ind][m] = 0;
        if(ind == 1)
        {
            dp[ind][m] += solve(ind, m-2, dp);
        }
        dp[ind][m] += solve(0, m-1, dp);
        return dp[ind][m];
    }
    long long countWays(int m)
    {
        vector<vector<int>>dp(2, vector<int>(m+1, -1));
        int ans = solve(1, m, dp);
        return ans;
    }
};

// { Driver Code Starts.
int main()
{
    //taking count of testcases
    int t;
    cin >> t;
    
    while(t--)
    {
        //taking stair count
        int m;
        cin>>m;
        Solution ob;
        cout<<ob.countWays(m)<<endl; // Print the output from our pre computed array
    }
    return 0;
}  // } Driver Code Ends
