// Question: Path with Maximum Probability
// Question Link: https://leetcode.com/problems/path-with-maximum-probability/

class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        // vector<vector<double>>graph(n, vector<double>(n, 0));
        vector<pair<int,double>>adj[n];
        for(int i=0; i<edges.size(); ++i)
        {
            adj[edges[i][0]].push_back({edges[i][1], succProb[i]});
            adj[edges[i][1]].push_back({edges[i][0], succProb[i]});
        }
        
        priority_queue< pair<double,int> >pq;
        vector<double>dp(n, 0);
        vector<bool>visited(n, false);
        
        dp[start] = 1;
        // visited[start] = true;
        pq.push({1, start});
        while(!pq.empty())
        {
            double cost = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            if(visited[node])
                continue;
            visited[node] = true;
            
            for(auto k:adj[node])
            {
                if(!visited[k.first])
                {
                    dp[k.first] = max(dp[k.first], cost*k.second);
                    pq.push({dp[k.first], k.first});
                }
            }
            
        }
        return dp[end];
    }
};
