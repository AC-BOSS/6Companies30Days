// Question: Time taken to burn a tree given starting node
// Question Link: https://practice.geeksforgeeks.org/problems/burning-tree/1/

class Solution {
  public:
    map<int,vector<int>>mp;
    void makeMap(Node* root)
    {
        queue<Node*>q;
        q.push(root);
        while(!q.empty())
        {
            Node* top = q.front();
            q.pop();
            int data = top->data;
            if(top->left)
            {
                mp[data].push_back(top->left->data);
                mp[top->left->data].push_back(data);
                q.push(top->left);
            }
            if(top->right)
            {
                mp[data].push_back(top->right->data);
                mp[top->right->data].push_back(data);
                q.push(top->right);
            }
        }
    }
    int minTime(Node* root, int target) 
    {
        makeMap(root);
      
        queue<int>q;
        q.push(target);
        unordered_set<int>st;
        st.insert(target);
        int time = -1;
        
        while(!q.empty())
        {
            int sz = q.size();
            while(sz--)
            {
                int top = q.front();
                q.pop();
                for(auto i:mp[top])
                {
                    if(st.find(i) == st.end())
                    {
                        q.push(i);
                        st.insert(i);
                    }
                }
            }
            ++time;
        }
        return time;
    }
};
