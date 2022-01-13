// Question: Alien Dictionary
// Question Link: https://practice.geeksforgeeks.org/problems/alien-dictionary/1/

class Solution{
    public:
    void dfs(int v, vector<int>adj[], int visited[], stack<int>&st)
	  {
	    visited[v] = 1;
	    int flag = 0;

	    for(auto i:adj[v])
	    {
	        if(!visited[i])
	        {
	            dfs(i, adj, visited, st);
	        }
	    }
	    st.push(v);
	  }
	vector<char> topoSort(int V, vector<int> adj[]) 
	{
	    stack<int>st;
	    int visited[V];
	    for(int i=0; i<V; ++i)
	        visited[i] = 0;
	    for(int i=0; i<V; ++i)
	        if(visited[i] == 0)
	            dfs(i, adj, visited, st);
	    vector<char>ans;
	    while(!st.empty())
	    {
	        ans.push_back(st.top()+'a');
	        st.pop();
	    }
	    return ans;
	}
    string findOrder(string dict[], int N, int K) {
        vector<int>adj[K];
        for(int i=1; i<N; ++i)
        {
            string a = dict[i-1];
            string b = dict[i];
            
            for(int j=0; j<min(a.length(), b.length()); ++j)
            {
                if(a[j] != b[j])
                {
                    adj[a[j] - 'a'].push_back(b[j] - 'a');
                    break;
                }
            }
        }
        vector<char>ans = topoSort(K, adj);
        string str;
        for(auto i:ans)
            str += i;
        return str;
    }
};
