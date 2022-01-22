// Question: Divide an array into two sets S1 and S2 such that the absolute difference between their sums is minimum and find the minimum difference
// Question Link: https://practice.geeksforgeeks.org/problems/minimum-sum-partition3317/1/

class Solution{

  public:
	int minDifference(int arr[], int n)  { 
	    int sum = 0;
	    for(int i=0; i<n; ++i)
	    {
	        sum += arr[i];
	    }
	    vector<vector<int>>dp(n+1, vector<int>(sum/2+1));
	    for(int i=1; i<=sum/2; ++i)
	        dp[0][i] = 0;
	    dp[0][0] = 1;
	    
	    for(int i=1; i<=n; ++i)
	    {
	        for(int j=0; j<=sum/2; ++j)
	        {
	            if(j < arr[i-1])
	                dp[i][j] = dp[i-1][j];
	            else
	                dp[i][j] = max(dp[i-1][j], dp[i-1][j-arr[i-1]]);
	        }
	    }
	    for(int i=sum/2; i>=0; --i)
	    {
	        if(dp[n][i] == 1)
	            return sum - 2*i;
	    }
	    return -1;
	} 
};
