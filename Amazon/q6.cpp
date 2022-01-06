// Question: Maximum of all subarrays of size k
// Question Link: https://practice.geeksforgeeks.org/problems/maximum-of-all-subarrays-of-size-k3101/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
  public:
    //Function to find maximum of each subarray of size k.
    vector <int> max_of_subarrays(int *arr, int n, int k)
    {
        deque<pair<int,int>>q(k);
        vector<int>ans;
        for(int i=0; i<k; ++i)
        {
            while(!q.empty() && q.back().first < arr[i])
            {
                q.pop_back();
            }
            q.push_back({arr[i], i});
        }
        ans.push_back(q.front().first);
        for(int i=k; i<n; ++i)
        {
            if(i - q.front().second >= k)
                q.pop_front();
            while(!q.empty() && q.back().first < arr[i])
            {
                q.pop_back();
            }
            
            q.push_back({arr[i],i});
            ans.push_back(q.front().first);
        }
        return ans;
    }
};

// { Driver Code Starts.

int main() {
	
	int t;
	cin >> t;
	
	while(t--){
	    
	    int n, k;
	    cin >> n >> k;
	    
	    int arr[n];
	    for(int i = 0;i<n;i++) 
	        cin >> arr[i];
	    Solution ob;
	    vector <int> res = ob.max_of_subarrays(arr, n, k);
	    for (int i = 0; i < res.size (); i++) 
	        cout << res[i] << " ";
	    cout << endl;
	    
	}
	
	return 0;
}  // } Driver Code Ends
