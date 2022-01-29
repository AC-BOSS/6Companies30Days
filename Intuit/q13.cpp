// Question: Minimum Swaps to Arrange a Binary Grid
// Question Link: https://leetcode.com/problems/minimum-swaps-to-arrange-a-binary-grid/

class Solution {
public:
    int solve(int begin, int end, vector<int>&arr)
    {
        if(begin >= end)
            return 0;
        int mid = (begin+end)/2;
        int left = solve(begin, mid, arr);
        int right = solve(mid+1, end, arr);
        int inv = left + right;
        
        int i = begin, j = mid+1;
        vector<int>temp;
        
        while(i<=mid && j<=end)
        {
            if(arr[i] < arr[j])
            {
                inv += (mid - i + 1);
                temp.push_back(arr[j++]);
            }
            else
                temp.push_back(arr[i++]);
        }
        
        while(i<=mid)
            temp.push_back(arr[i++]);
        while(j<=end)
            temp.push_back(arr[j++]);
        for(int i=0; i<temp.size(); ++i)
        {
            arr[begin+i] = temp[i];
        }
        return inv;
    }
    int minSwaps(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        vector<int>arr(m);
        unordered_set<int>st;
        for(int i=0; i<m; ++i)
        {
            arr[i] = 0;
            for(int j=n-1; j>=0; --j)
            {
                if(grid[i][j] == 0)
                    ++arr[i];
                else
                    break;
            }
            while(st.count(arr[i]))
                --arr[i];
            st.insert(arr[i]);
        }
        vector<int>sorted = arr;
        sort(sorted.begin(), sorted.end(), greater<int>());
        
        map <int, int> h;

        for(int i=0; i<m; ++i)
        {
            if(sorted[i] < n-1-i)
                return -1;
        }
        int ans = solve(0, m-1, arr);
        return ans;
    }
};
