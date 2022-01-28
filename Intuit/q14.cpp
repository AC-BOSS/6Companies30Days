// Question: As Far from Land as Possible
// Question Link: https://leetcode.com/problems/as-far-from-land-as-possible/

class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<int>>dp(m, vector<int>(n, -1));
        queue<pair<int,int>>q;
        int flag = 0;
        for(int i=0; i<m; ++i)
        {
            for(int j=0; j<n; ++j)
            {
                if(grid[i][j] == 1)
                {
                    flag = 1;
                    dp[i][j] = 0;
                    q.push({i,j});
                }
            }
        }
        if(!flag)
            return -1;
        while(!q.empty())
        {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            if(c+1 < n && (dp[r][c+1] == -1))
            {
                dp[r][c+1] = dp[r][c] + 1;
                q.push({r, c+1});
            }
            if(c-1 >= 0 && (dp[r][c-1] == -1))
            {
                dp[r][c-1] = dp[r][c] + 1;
                q.push({r, c-1});
            }
            if(r+1 < m && (dp[r+1][c] == -1))
            {
                dp[r+1][c] = dp[r][c] + 1;
                q.push({r+1, c});
            }
            if(r-1 >= 0 && (dp[r-1][c] == -1))
            {
                dp[r-1][c] = dp[r][c] + 1;
                q.push({r-1, c});
            }
        }
        int ans = 0;
        for(int i=0; i<m; ++i)
        {
            for(int j=0; j<n; ++j)
                ans = max(ans, dp[i][j]);
        }
        if(ans == 0)
            return -1;
        return ans;
    }
};
