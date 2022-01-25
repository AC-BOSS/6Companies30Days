// Question: Find in Mountain Array
// Question Link: https://leetcode.com/problems/find-in-mountain-array/

/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray &arr) {
        int n = arr.length();
        int dp[n];
        for(int i=0;i<n; ++i)
            dp[i] = -1;
        int s=0, e=n-1, peak;
        while(s <= e)
        {
            int m = s - (s-e)/2;
            dp[m] = arr.get(m);

            if(m == 0)
            {
                s = m+1;
                continue;
            }
            else if(m == n-1)
            {
                e = m-1;
                continue;
            }
            dp[m-1] = arr.get(m-1);
            dp[m+1] = arr.get(m+1);
            
            if(dp[m-1] < dp[m] && dp[m] > dp[m+1])
            {
                peak = m;
                break;
            }
            else if(dp[m-1] < dp[m] && dp[m] < dp[m+1])
                s = m+1;
            else if(dp[m-1] > dp[m] && dp[m] > dp[m+1])
                e = m-1;
        }
        s = 0;
        e = peak;
        int ans = -1;
        // cout<<s<<' '<<e<<endl;
        while(s <= e)
        {
            int m = s - (s-e)/2;
            if(dp[m] == -1)
            {
                dp[m] = arr.get(m);
            }
            if(dp[m] == target)
            {
                ans = m;
                e = m-1;
            }
            else if(dp[m] < target)
                s = m+1;
            else if(dp[m] > target)
                e = m-1;
        }
        if(ans != -1)
            return ans;
        s = peak;
        e = n-1;
        // cout<<s<<' '<<e<<endl;
        while(s<=e)
        {
            int m = s - (s-e)/2;
            if(dp[m] == -1)
                dp[m] = arr.get(m);
            
            if(dp[m] == target)
            {
                ans = m;
                e = m-1;
            }
            else if(dp[m] > target)
                s = m+1;
            else if(dp[m] < target)
                e = m-1;
        }
        return ans;
    }
};
