// Question: Stickler Thief
// Question Link: https://practice.geeksforgeeks.org/problems/stickler-theif-1587115621/1/

class Solution
{
    public:
    //Function to find the maximum money the thief can get.
    int FindMaxSum(int arr[], int n)
    {
        // Your code here
        int dp[n];
        if(n==1)
        {
            return arr[0];
        }
        if(n==2)
        {
            return max(arr[0],arr[1]);
        }
        dp[0]=arr[0];
        dp[1]=arr[1];
        dp[2]=arr[2]+arr[0];
        for(int i=3;i<n;i++)
        {
            dp[i]=max(arr[i]+dp[i-2],arr[i]+dp[i-3]);
        }
        return max(dp[n-1],dp[n-2]);
    }
};
