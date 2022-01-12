// Question: Matrix Traversal in Spiral Form
// Question Link: https://practice.geeksforgeeks.org/problems/spirally-traversing-a-matrix-1587115621/1/

class Solution
{   
    public: 
    //Function to return a list of integers denoting spiral traversal of matrix.
    vector<int> spirallyTraverse(vector<vector<int> > matrix, int r, int c) 
    {
        // code here
        vector<int>ans;
        int startrow=0;
        int startcol=0;
        int endrow=r-1;
        int endcol=c-1;
        while(startrow<=endrow && startcol<=endcol)
        {
            for(int i=startcol;i<=endcol;i++)
            {
                ans.push_back(matrix[startrow][i]);
            }
            startrow++;
            if(startrow>endrow)
                break;
            
            for(int i=startrow;i<=endrow;i++)
            {
                ans.push_back(matrix[i][endcol]);
            }
            endcol--;
            if(startcol>endcol)
                break;
            
            for(int i=endcol;i>=startcol;i--)
            {
                ans.push_back(matrix[endrow][i]);
            }
            endrow--;
            for(int i=endrow;i>=startrow;i--)
            {
                ans.push_back(matrix[i][startcol]);
            }
            startcol++;
        }
        return ans;
    }
};
