// Question: Brackets in Matrix Chain Multiplication
// Question Link: https://practice.geeksforgeeks.org/problems/brackets-in-matrix-chain-multiplication1024/1/

class Solution{
public:
    string ans;
    void print_br(int s, int e, int**br)
    {
        if(s == e)
        {
            ans += ('A'+s-1);
            return;
        }
        ans += "(";
        print_br(s, br[s][e], br);
        print_br(br[s][e] + 1, e, br);
        ans += ")";
    }
    string matrixChainOrder(int p[], int n){
        int**br = (int**)malloc(sizeof(int*)*n);
        for(int i=0; i<n; ++i)
        {
            br[i] = (int*)malloc(sizeof(int)*n);
        }
        int m[n][n];

        for(int i=0; i<n; ++i)
        {
            for(int j=0; j<n; ++j)
            {
                if(i != j)
                    m[i][j] = -1;
                else
                    m[i][j] = 0;
            }   
        }
    
        for(int l=2; l<=n-1; ++l)
        {
            for(int i=1; i+l-1 < n; ++i)
            {
                int j = i+l-1;
                for(int k=i; k<j; ++k)
                {
                    int q = m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j];
                    if(m[i][j] < 0 || q < m[i][j])
                    {
                        m[i][j] = q;
                        br[i][j] = k;
                    }
                }
            }
        }
        print_br(1, n-1, br);
        return ans;
    }
};
