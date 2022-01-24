// Question: Longest Arithmetic Progression 
// Question Link: https://practice.geeksforgeeks.org/problems/longest-arithmetic-progression1019/1

class Solution{   
public:
    int lengthOfLongestAP(int arr[], int n) {
        // code here
        if(n==1)
            return 1;
        vector<vector<int>>dp(n, vector<int>(n, 2));
        int ans = 2;
        for(int j=n-2; j>0; --j)
        {
            int i=j-1, k=i+1;
            while(i>=0 && k<n)
            {
                if(arr[i] + arr[k] == 2*arr[j])
                {
                    dp[i][j] = dp[j][k]+1;
                    ans = max(ans, dp[i][j]);
                    --i;
                    ++k;
                }
                else if(arr[i] + arr[k] > 2*arr[j])
                    --i;
                else
                    ++k;
            }
        }
        return ans;
    }
};
