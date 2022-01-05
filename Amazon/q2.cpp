// Question: Longest Mountain in Array
// Question Link: https://leetcode.com/problems/longest-mountain-in-array

class Solution {
public:
    int longestMountain(vector<int>& arr) {
        bool inc=false, dec=false;
        int begin=-1, ans = 0, n=arr.size();
        for(int i=1; i<n; ++i)
        {
            if(!inc && !dec)
            {
                if(arr[i] > arr[i-1])
                {
                    begin = i-1;
                    inc = true;
                }
            }
            else if(inc)
            {
                if(arr[i] < arr[i-1])
                {
                    inc = false;
                    dec = true;
                }
                else if(arr[i] == arr[i-1])
                {
                    inc = false;
                    dec = false;
                }
            }
            else if(dec)
            {
                if(arr[i] > arr[i-1])
                {
                    ans = max(i-begin, ans);
                    begin = i-1;
                    dec = false;
                    inc = true;
                }
                else if(arr[i] == arr[i-1])
                {
                    ans = max(i-begin, ans);
                    dec = false;
                    inc = false;
                }
            }
        }
        if(dec)
            ans = max(n-begin, ans);
        return ans;
    }
};
