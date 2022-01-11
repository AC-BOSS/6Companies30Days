// Question: Possible Words from Phone Digits
// Question Link: https://practice.geeksforgeeks.org/problems/possible-words-from-phone-digits-1587115620/1

class Solution
{
    public:
    map<int, vector<char>>mp;
    //Function to find list of all words possible by pressing given numbers.
    void solve(int ind, int a[], int n, string &temp, vector<string>&ans)
    {
        if(ind >= n)
        {
            ans.push_back(temp);
            return;
        }
        for(auto i:mp[a[ind]])
        {
            temp += i;
            solve(ind+1, a, n, temp, ans);
            temp.pop_back();
        }
    }
    vector<string> possibleWords(int a[], int N)
    {
        
        mp[2] = {'a', 'b', 'c'};
        mp[3] = {'d', 'e', 'f'};
        mp[4] = {'g', 'h', 'i'};
        mp[5] = {'j', 'k', 'l'};
        mp[6] = {'m', 'n', 'o'};
        mp[7] = {'p', 'q', 'r', 's'};
        mp[8] = {'t', 'u', 'v'};
        mp[9] = {'w', 'x', 'y', 'z'};
        
        vector<string>ans;
        string temp;
        solve(0, a, N, temp, ans);
        return ans;
    }
};
