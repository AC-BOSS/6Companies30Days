// Question: Express as sum of power of natural numbers 
// Question Link: https://practice.geeksforgeeks.org/problems/express-as-sum-of-power-of-natural-numbers5647/1

class Solution{
    public:
    const int mod = 1e9+7;
    int helper(int n,int x,int num, vector<vector<int>>&dp)
    {
        int temp=pow(num,x);
        int ans = 0;
        if(num <= 0)
            return 0;
        if(dp[n][num]!=-1)
        {
            return dp[n][num];
        }
        if(n==temp)
        {
            ans = 1;
        }
        if(temp>n)
        {
            return dp[n][num]=helper(n,x,num-1,dp)%mod;
        }
        int a = helper(n-temp,x,num-1,dp)%mod;
        int b = helper(n,x,num-1,dp)%mod;
        return dp[n][num]= (a+b+ans)%mod;
    }
    int numOfWays(int n, int x)
    {
        // code here
        vector<vector<int>>dp(n+1,vector<int>((int)pow(n,1.0/x)+1,-1));
        // cout<<(int)pow(n,1.0/x)<<endl;
        
        int ans = helper(n,x,(int)pow(n,1.0/x),dp);
        // for(int i=0; i<=n; ++i)
        // {
        //     for(int j=0; j<=(int)pow(n, 1.0/x); ++j)
        //         cout<<dp[i][j]<<' ';
        //     cout<<endl;
        // }
        return ans;
    }
};
