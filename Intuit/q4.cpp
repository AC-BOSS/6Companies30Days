// Question: Largest number in K swaps 
// Question Link: https://practice.geeksforgeeks.org/problems/largest-number-in-k-swaps-1587115620/1

class Solution
{
    public:
    string ans;
    //Function to find the largest number after k swaps.
    void solve(string& str,int k,int idx)
    {
        // cout<<str<<endl;
        if(idx >= str.size() || k<=0)
        {
            if(str > ans)
            {
                ans = str;
                // cout<<str<<endl;
            }
            return;
        }

        char max = str[idx];
        for(int i=idx; i<str.size(); ++i)
        {
            if(str[i] > max)
                max = str[i];
        }
        if(max == str[idx])
        {
            solve(str, k, idx+1);
            return;
        }
        else
            --k;
        for(int i=idx+1; i<str.size(); ++i)
        {
            if(max == str[i])
            {
                swap(str[i], str[idx]);
                solve(str, k, idx+1);
                swap(str[i], str[idx]);
            }
        }
    }
    //Function to find the largest number after k swaps.
    string findMaximumNum(string str, int k)
    {
        ans = str;
        solve(str,k,0);
        return ans;
    }
};
