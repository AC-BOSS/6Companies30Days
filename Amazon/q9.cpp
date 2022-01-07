// Question: Is Sudoku Valid?
// Question Link: https://practice.geeksforgeeks.org/problems/is-sudoku-valid4820/1

#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    bool validRow(vector<vector<int>>&mat, int row, int col)
    {
        for(int i=0; i<9; ++i)
        {
            // cout<<row<<' '<<i<<endl;
            if(i!= col && mat[row][i] == mat[row][col])
                return false;
        }
        return true;
    }
    bool validCol(vector<vector<int>>&mat, int row, int col)
    {
        for(int i=0; i<9; ++i)
        {
            if(i!=row && mat[i][col] == mat[row][col])
                return false;
        }
        return true;
    }
    bool validBox(vector<vector<int>>&mat, int row, int col)
    {
        int startRow = row/3*3, startCol = col/3*3, endRow = startRow+3, endCol = startCol+3;
        for(int i=startRow; i<endRow; ++i)
        {
            for(int j=startCol; j<endCol; ++j)
            {
                if((i!=row || j!= col) && mat[i][j] == mat[row][col])
                    return false;
            }
        }
        return true;
    }
    int isValid(vector<vector<int>> mat){
        for(int i=0; i<9; ++i)
        {
            for(int j=0; j<9; ++j)
            {
                // cout<<i<<' '<<j<<endl;
                if(mat[i][j]>0 && (!validRow(mat, i, j) || !validCol(mat,i,j) || !validBox(mat,i,j)))
                    return 0;
            }
        }
        return 1;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        vector<vector<int>> mat(9, vector<int>(9, 0));
        for(int i = 0;i < 81;i++)
            cin>>mat[i/9][i%9];
        
        Solution ob;
        cout<<ob.isValid(mat)<<"\n";
    }
    return 0;
}  // } Driver Code Ends
