// Question: Number of Provinces
// Question Link: https://leetcode.com/problems/number-of-provinces/

class Solution {
public:
    int findSet(int n, vector<int>&ds)
    {
        if(ds[n] != n)
            ds[n] = findSet(ds[n], ds);
        return ds[n];
    }
    void link(int a, int b, vector<int>&ds)
    {
        ds[a] = findSet(a, ds);
        ds[b] = findSet(b, ds);
        
        ds[ds[a]] = ds[b];
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        int ans = 0;
        vector<int>ds(n+1);
        for(int i=1; i<=n; ++i)
            ds[i] = i;
        for(int i=0; i<n; ++i)
        {
            for(int j=i+1; j<n; ++j)
            {
                if(isConnected[i][j] == 1)
                    link(i+1, j+1, ds);
            }
        }
        for(int i=1; i<=n; ++i)
        {
            if(ds[i] == i)
                ++ans;
        }
        return ans;
    }
};
