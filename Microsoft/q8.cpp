// Question: Connect Nodes at Same Level
// Question Link: https://practice.geeksforgeeks.org/problems/connect-nodes-at-same-level/1/

class Solution
{
    public:
    //Function to connect nodes at same level.
    void connect(Node *root)
    {
       // Your Code Here
       queue<Node*>q;
       q.push(root);
       while(!q.empty())
       {
           Node* node=q.front();
           q.pop();
           int sz=q.size();
           if(node->left)
               {
                   q.push(node->left);
               }
           if(node->right)
               {
                   q.push(node->right);
               }
           while(sz--)
           {
               Node* n1= q.front();
               q.pop();
               if(n1->left)
               {
                   q.push(n1->left);
               }
               if(n1->right)
               {
                   q.push(n1->right);
               }
               node->nextRight=n1;
               node=n1;
           }
           node->nextRight=NULL;
       }
    }     
};
