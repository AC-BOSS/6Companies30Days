// Question: Pacific Atlantic Water Flow
// Question Link: https://leetcode.com/problems/pacific-atlantic-water-flow/

class Solution {
public:
    void dfs(int i, int j, vector<vector<int>>&dp, vector<vector<int>>&heights, int h, int val)
    {
        int m = heights.size();
        int n = heights[0].size();
        if(i<0 || i>=m || j<0 || j>=n)
            return;
        if(dp[i][j] == 3 || dp[i][j] == val)
            return;
        
        if(heights[i][j] < h)
            return;
            
        if(dp[i][j] == 0)
            dp[i][j] = val;
        else
        {
            val = 3;
            dp[i][j] = 3;
        }
        
        dfs(i+1, j, dp, heights, heights[i][j], val);
        dfs(i-1, j, dp, heights, heights[i][j], val);
        dfs(i, j+1, dp, heights, heights[i][j], val);
        dfs(i, j-1, dp, heights, heights[i][j], val);
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        vector<vector<int>>dp(m, vector<int>(n, 0));
        vector<vector<int>>ans;
        
        dfs(0, n-1, dp, heights, heights[0][n-1], 3);
        dfs(m-1, 0, dp, heights, heights[m-1][0], 3);
        
        for(int i=0; i<n; ++i)
            dfs(0, i, dp, heights, heights[0][i], 1);
        for(int i=0; i<m; ++i)
            dfs(i, 0, dp, heights, heights[i][0], 1);
        
        for(int i=0; i<n; ++i)
            dfs(m-1, i, dp, heights, heights[m-1][i], 2);
        for(int i=0; i<m; ++i)
            dfs(i, n-1, dp, heights, heights[i][n-1], 2);
        
        // for(int i=0; i<m; ++i)
        // {
        //     for(int j=0; j<n; ++j)
        //         cout<<dp[i][j]<<' ';
        //     cout<<endl;
        // }
        for(int i=0; i<m; ++i)
        {
            for(int j=0; j<n; ++j)
            {
                if(dp[i][j] == 3)
                    ans.push_back({i,j});
            }
        }
        return ans;
    }
};
