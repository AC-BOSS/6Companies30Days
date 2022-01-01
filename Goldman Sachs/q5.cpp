// Question: Program to find Nth Ugly Number
// Question Link: https://practice.geeksforgeeks.org/problems/ugly-numbers2254/1

#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long

class Solution{
public:	
	// #define ull unsigned long long
	/* Function to get the nth ugly number*/
    ull getNthUglyNo(int n) {
	    vector<ull>dp;
	    dp.push_back(1);
	    int two=0, three=0, five=0;
	    for(int i=0; i<n-1; ++i)
	    {
	        ull mini = min(dp[two]*2, min(dp[three]*3, dp[five]*5));
	        dp.push_back(mini);
	        if(mini == dp[two]*2)
	            ++two;
	        if(mini == dp[three]*3)
	            ++three;
	        if(mini == dp[five]*5)
	            ++five;
	    }
	    return dp[n-1];
	}
};

// Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        auto ans = ob.getNthUglyNo(n);
        cout << ans << "\n";
    }
    return 0;
}
  // Driver Code Ends
