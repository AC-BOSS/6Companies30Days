// Question: Generate Parentheses 
// Question Link: https://practice.geeksforgeeks.org/problems/generate-all-possible-parentheses/1/

class Solution
{
    public:
    void helper(int totalopen,int open,string res,vector<string>&ans)
    {
        if(totalopen==0 && open==0)
        {
            ans.push_back(res);
            return ;
        }
        if(totalopen>0)
        {
            helper(totalopen-1,open+1,res+"(",ans);
        }
        if(open>0)
        {
            helper(totalopen,open-1,res+")",ans);
        }
    }
    vector<string> AllParenthesis(int n) 
    {
        vector<string>ans;
        helper(n,0,"",ans);
        return ans;
    }
};
