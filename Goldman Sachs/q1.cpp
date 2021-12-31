// Question: Given an array of strings, return all groups of strings that are anagrams.
// Question Link: https://practice.geeksforgeeks.org/problems/print-anagrams-together/1

#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

class Solution{
  public:
    vector<vector<string> > Anagrams(vector<string>& string_list) {
        //code here
        map<string, vector<int>>mp;
        vector<vector<string>>ans;
    
        for(int i=0; i<string_list.size(); ++i)
        {
            string sorted = string_list[i];
            sort(sorted.begin(), sorted.end());
            auto it = mp.find(sorted);
            
            if(it == mp.end())
                mp[sorted] = {i};
            else
                it->second.push_back(i);
        }
        for(auto i:mp)
        {
            vector<string>temp;
            for(auto j:i.second)
            {
                temp.push_back(string_list[j]);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};

// Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<string> string_list(n);
        for (int i = 0; i < n; ++i)
            cin>>string_list[i]; 
        Solution ob;
        vector<vector<string> > result = ob.Anagrams(string_list);
        sort(result.begin(),result.end());
        for (int i = 0; i < result.size(); i++)
        {
            for(int j=0; j < result[i].size(); j++)
            {
                cout<<result[i][j]<<" ";
            }
            cout<<"\n";
        }
    }

    return 0;
}
  // Driver Code Ends
