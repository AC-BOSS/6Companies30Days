// Question: Column name from a given column number
// Question Link: https://practice.geeksforgeeks.org/problems/column-name-from-a-given-column-number4244/1/

class Solution{
    public:
    string colName (long long int n)
    {
        string ans;
        while(n>0)
        {
            if(n%26==0)
            {
                ans += 'Z';
                n=n/26-1;
            }
            else
            {
                ans += ('A' + n%26-1);
                n/=26;
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
