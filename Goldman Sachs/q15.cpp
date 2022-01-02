// Question: Array Pair Sum Divisibility Problem
// Question Link: https://practice.geeksforgeeks.org/problems/array-pair-sum-divisibility-problem3257/1

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool canPair(vector<int> nums, int k) {
        if(k==1)
            return (nums.size()%2==0);
        int count[k];
        for(int i=0; i<k; ++i)
            count[i] = 0;
        for(auto i:nums)
        {
            ++count[i%k];
        }
        // for(int i=0; i<k; ++i)
        //     cout<<count[i]<<' ';
        // cout<<endl;
        if(k%2==0 && count[k/2]&1)
            return false;
        for(int i=1; i+i<k; ++i)
        {
            if(count[i] != count[k-i])
                return false;
        }
        return true;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, k;
        cin >> n >> k;
        vector<int> nums(n);
        for (int i = 0; i < nums.size(); i++) cin >> nums[i];
        Solution ob;
        bool ans = ob.canPair(nums, k);
        if (ans)
            cout << "True\n";
        else
            cout << "False\n";
    }
    return 0;
}  // } Driver Code Ends
