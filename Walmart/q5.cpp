// Question: Transform to Sum Tree
// Question Link: https://practice.geeksforgeeks.org/problems/transform-to-sum-tree/1/

class Solution {
  public:
    int solve(Node* node)
    {
        if(node == NULL)
            return 0;
        int left = solve(node->left);
        int right = solve(node->right);
        
        int temp = node->data;
        node->data = left + right;
        return node->data + temp;
    }
    void toSumTree(Node *node)
    {
        solve(node);
    }
};
