// Question: Unit Area of largest region of 1's 
// Question Link: https://practice.geeksforgeeks.org/problems/length-of-largest-region-of-1s-1587115620/1/

class Solution
{
    public:
    //Function to find unit area of the largest region of 1s.
    bool isOne(vector<vector<int>>&grid, int r, int c)
    {
        int m = grid.size();
        int n = grid[0].size();
        
        if(r<0 || r>=m || c<0 || c>=n)
            return false;
        return (grid[r][c] == 1);
    }
    int bfs(int r, int c, vector<vector<int>>&grid)
    {
        queue<pair<int,int>>q;
        q.push({r, c});
        grid[r][c] = 0;
        int ans = 1;
        while(!q.empty())
        {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            
            for(int i=-1; i<=1; i++)
            {
                for(int j=-1; j<=1; ++j)
                {
                    if(i==0 && j==0)
                        continue;
                    if(isOne(grid, r+i, c+j))
                    {
                        ++ans;
                        grid[r+i][c+j] = 0;
                        q.push({r+i, c+j});
                    }
                }
            }
        }
        return ans;
    }
    int findMaxArea(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        // vector<vector<int>>visited(m, vector<int>(n, 0));
        int ans = 0;
        
        for(int i=0; i<m; ++i)
        {
            for(int j=0; j<n; ++j)
            {
                if(grid[i][j] == 1)
                {
                    ans = max(ans, bfs(i, j, grid));
                }
            }
        }
        return ans;
    }
};
