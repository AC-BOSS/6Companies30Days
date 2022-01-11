// Question: Prerequisite Tasks
// Question Link: https://practice.geeksforgeeks.org/problems/prerequisite-tasks/1

class Solution {
public:
    bool checkCycle(int n, vector<int>adj[], int status[])
    {
        status[n] = 1;
        for(auto i:adj[n])
        {
            if(status[i] == 1)
                return true;
            if(status[i] == 0 && checkCycle(i, adj, status))
                return true;
        }
        status[n] = 2;
        return false;
    }
	bool isPossible(int N, vector<pair<int, int> >& prerequisites) {
	    vector<int>adj[N];
	    for(auto p:prerequisites)
	    {
	        adj[p.second].push_back(p.first);
	    }
	    int status[N];
	    for(int i=0; i<N; ++i)
	        status[i] = 0;
	    for(int i=0; i<N; ++i)
	    {
	        if(status[i] == 0 && checkCycle(i, adj, status))
	            return false;
	    }
	    return true;
	}
};
