// Question: Tree Serialization and Deserialization
// Question Link: https://practice.geeksforgeeks.org/problems/serialize-and-deserialize-a-binary-tree/1

class Solution
{
    public:
    //Function to serialize a tree and return a list containing nodes of tree.
    vector<int> serialize(Node *root) 
    {
        //Your code here
        vector<int>ans;
        queue<Node*>q;
        q.push(root);
        while(!q.empty())
        {
            Node* node = q.front();
            q.pop();
            if(!node)
            {
                //pushing -1 if node doesnt exist
                ans.push_back(-1);
            }
            else
            {
                //pushing node value if it exists to ans
                ans.push_back(node->data);
                //then push left and right of node
                q.push(node->left);
                q.push(node->right);
            }
        }
        return ans;
    }
    
    //Function to deserialize a list and construct the tree.
    Node * deSerialize(vector<int> &a)
    {
       //Your code here
       //making root
       Node* root = new Node(a[0]);
       queue<Node*>q;
       //keep current pointer to node in array a
       int index=1;
       //push the root in  queue
       q.push(root);
       while(!q.empty())
       {
           Node* node = q.front();
           q.pop();
           //check -1 or not
           if(a[index]!=-1)
           {
               node->left=new Node(a[index]);
               q.push(node->left);
           }
           //move pointer to array to next position
           index++;
           if(a[index]!=-1)
           {
               node->right=new Node(a[index]);
               q.push(node->right);
           }
           index++;
       }
       return root;
    }
};
