// Question: Find the kid which gets the damaged toy
// Question Link:https://practice.geeksforgeeks.org/problems/find-the-position-of-m-th-item1723/1

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int findPosition(int N , int M , int K) {
        // code here
        M = M%N;
        return (K+M-2)%N+1;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N,M,K;
        
        cin>>N>>M>>K;

        Solution ob;
        cout << ob.findPosition(N,M,K) << endl;
    }
    return 0;
}  // } Driver Code Ends
