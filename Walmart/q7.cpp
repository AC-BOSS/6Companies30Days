// Question: Sorted subsequence of size 3 
// Question Link: https://practice.geeksforgeeks.org/problems/sorted-subsequence-of-size-3/1/

class Solution{
  public:
    vector<int> find3Numbers(vector<int> arr, int n) {
        vector<int>mini(n), maxi(n);
        mini[0] = arr[0];
        maxi[n-1] = arr[n-1];
        for(int i=1; i<n; ++i)
            mini[i] = min(mini[i-1], arr[i]);
        for(int i=n-2; i>=0; --i)
            maxi[i] = max(maxi[i+1], arr[i]);
            
        vector<int>ans;
        for(int i=1; i<n-1; ++i)
        {
            if(arr[i] != mini[i] && arr[i] != maxi[i])
            {
                ans.push_back(mini[i]);
                ans.push_back(arr[i]);
                ans.push_back(maxi[i]);
                break;
            }
        }
        return ans;
    }
};
