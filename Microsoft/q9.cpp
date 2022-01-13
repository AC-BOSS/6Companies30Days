// Question: Count Number of SubTrees having given Sum
// Question Link: https://practice.geeksforgeeks.org/problems/count-number-of-subtrees-having-given-sum/1/

int helper(Node* root,int x,int &ans)
{
    if(!root)
	{
	    return 0;
	}
	int left=helper(root->left,x,ans);
	int right=helper(root->right,x,ans);
	if(root->data+left+right == x)
	{
	   // cout<<root->data<<" ";
	    ans++;
	}
	return root->data+left+right;
}

int countSubtreesWithSumX(Node* root, int x)
{
	// Code here
	int ans=0;
	helper(root,x,ans);
	return ans;
}
