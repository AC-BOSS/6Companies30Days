// Question: Total Decoding Messages
// Question Link: https://practice.geeksforgeeks.org/problems/total-decoding-messages1235/1
// Time Complexity: O(n)
// Space Complexity: O(n)

#include<bits/stdc++.h>
using namespace std;

class Solution {
	public:
	    const int MOD = 1e9+7;
	    int solve(string str, int ind, vector<int>&dp)
	    {
	        if(ind == str.size())
	            return 1;
	        if(dp[ind] >= 0)
	            return dp[ind];
	        else if(str[ind] == '0')
	            dp[ind] = 0;
	        else if(ind == str.size()-1)
	        {
	            dp[ind] = 1;
	        }
	        else if(str[ind] == '1')
	        {
	           dp[ind] = (solve(str, ind+1, dp)%MOD + solve(str, ind+2, dp)%MOD)%MOD;
	        }
	        else if(str[ind] == '2')
	        {
	            if(str[ind+1] <= '6' && str[ind+1] >= '0')
	                dp[ind] = (solve(str, ind+2, dp)%MOD + solve(str, ind+1, dp)%MOD)%MOD;
	            else
	                dp[ind] = solve(str, ind+1, dp) % MOD;
	        }
	        else
	            dp[ind] = solve(str, ind+1, dp) % MOD;
	        return dp[ind];
	    }
		int CountWays(string str){
		    // Code here
		    int n = str.size();
		    vector<int>dp(n, -1);
		    return solve(str, 0, dp);
		}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution obj;
		int ans = obj.CountWays(str);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends
