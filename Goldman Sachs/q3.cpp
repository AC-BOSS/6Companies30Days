// Question: Count the subarrays having product less than k
// Question Link: https://practice.geeksforgeeks.org/problems/count-the-subarrays-having-product-less-than-k1708/1

#include <bits/stdc++.h>
using namespace std;

class Solution{
  public:
    int countSubArrayProductLessThanK(const vector<int>& a, int n, long long k) {
        int ans = 0, start=0, end=-1;
        long long curr=a[0];
        while(end < n)
        {
            if(start > end)
            {
                curr = a[++end];
            }
            else if(curr < k)
            {
                ans += (end-start+1);
                // cout<<end<<' '<<ans<<endl;
                curr*=a[++end];
            }
            else if(curr >= k)
            {
                curr/=a[start++];
            }
        }
        return ans;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        long long int k;
        cin >> n >> k;
        vector<int> arr(n);
        for (i = 0; i < n; i++) cin >> arr[i];
        Solution obj;
        cout << obj.countSubArrayProductLessThanK(arr, n, k) << endl;
    }
    return 0;
}
  // } Driver Code Ends
