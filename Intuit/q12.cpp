// Question: Course Schedule II
// Question Link: https://leetcode.com/problems/course-schedule-ii/

class Solution {
public:
    bool dfs(int v, vector<int>adj[], int status[], stack<int>&st)
    {
        // cout<<v<<' ';
        status[v] = 1;
        for(auto i:adj[v])
        {
            if(status[i] == 1)
            {
                // cout<<v<<':'<<i<<endl;
                return false;
            }
            if(status[i] == 0)
            {
                if(!dfs(i,adj,status, st))
                    return false;
            }
        }
        status[v] = 2;
        st.push(v);
        return true;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>ans;
        stack<int>st;
        vector<int>adj[numCourses];
        int status[numCourses];
        for(auto k:prerequisites)
            adj[k[1]].push_back(k[0]);
        for(int i=0; i<numCourses; ++i)
            status[i] = 0;
        
        for(int i=0; i<numCourses; ++i)
        {
            if(status[i] == 0)
            {
                if(!dfs(i,adj,status,st))
                {
                    // cout<<i<<endl;
                    return ans;   
                }
            }
        }
        cout<<st.size();
        while(!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
};
