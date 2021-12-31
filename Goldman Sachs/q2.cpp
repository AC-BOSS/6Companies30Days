//Question: Overlapping Rectangles
//Question Link: https://practice.geeksforgeeks.org/problems/overlapping-rectangles1924/1/

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int doOverlap(int l1[], int r1[], int l2[], int r2[]) {
        // code here
        if(l2[0] > r1[0] || l1[0] > r2[0] || l1[1] < r2[1] || l2[1] < r1[1])
            return false;
        return true;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int p[2], q[2], r[2], s[2];
        cin >> p[0] >> p[1] >> q[0] >> q[1] >> r[0] >> r[1] >> s[0] >> s[1];
        Solution ob;
        int ans = ob.doOverlap(p, q, r, s);
        cout << ans << "\n";
    }
}  // } Driver Code Ends
