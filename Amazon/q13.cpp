// Question: Rotting Oranges
// Question Link: https://leetcode.com/problems/rotting-oranges/

class Solution {
public:
    bool isFresh(int row, int col, vector<vector<int>>& grid)
    {
        if(row < 0 || row >= grid.size())
            return false;
        if(col < 0 || col >= grid[0].size())
            return false;
        if(grid[row][col] == 1)
        {
            grid[row][col] = 2;
            return true;
        }
        return false;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        queue<pair<int,int>>q;
        for(int i=0; i<m; ++i)
        {
            for(int j=0; j<n; ++j)
            {
                if(grid[i][j] == 2)
                {
                    q.push({i,j});
                }
            }
        }
        q.push({-1,-1});
        int time = -1;
        while(!q.empty())
        {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            if(row == -1 && col == -1)
            {
                ++time;
                if(q.empty())
                    break;
                else
                {
                    q.push({-1,-1});
                    continue;
                }
            }
            
            if(isFresh(row+1, col, grid))
                q.push({row+1, col});
            if(isFresh(row-1, col, grid))
                q.push({row-1, col});
            if(isFresh(row, col+1, grid))
                q.push({row, col+1});
            if(isFresh(row, col-1, grid))
                q.push({row, col-1});
        }
        for(int i=0; i<m; ++i)
        {
            for(int j=0; j<n; ++j)
                if(grid[i][j] == 1)
                    return -1;
        }
        return time;
    }
};
