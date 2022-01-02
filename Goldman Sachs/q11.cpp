// Question:  Given an unsorted array Arr of size N of positive integers. One number 'A' from     set {1, 2, …N} is missing and one number 'B' occurs twice in array. Find these two numbers.
// Question Link:  https://practice.geeksforgeeks.org/problems/find-missing-and-repeating2512/1/
// Time - O(n)
// space- O(1)

#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    int *findTwoElement(int *arr, int n) {
        // code here
        int* ans = (int*)malloc(sizeof(int)*2);
        
        for(int i=0;i<n;i++)
        {
            if(arr[abs(arr[i])-1]<=0)
            {
                ans[0]=abs(arr[i]);
            }
            else
            {
                arr[abs(arr[i])-1] *=-1;
            }
        }
        for(int i=0;i<n;i++)
        {
            if(arr[i]>0)
            {
                ans[1]=i+1;
                break;
;            }
        }
        return ans;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}  // } Driver Code Ends
