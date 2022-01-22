// Question: Winner of an election 
// Question Link: https://practice.geeksforgeeks.org/problems/winner-of-an-election-where-votes-are-represented-as-candidate-names-1587115621/1

class Solution{
  public:
  
    //Function to return the name of candidate that received maximum votes.
    vector<string> winner(string arr[],int n)
    {
        // Your code here
        // Return the string containing the name and an integer
        // representing the number of votes the winning candidate got
        map<string,int>mp;
        vector<string>ans;
        for(int i=0;i<n;i++)
        {
            mp[arr[i]]++;
        }
        int maxans=0;
        string maxstr="";
        for(auto x:mp)
        {
            if(x.second>maxans)
            {
                maxans=x.second;
                maxstr=x.first;
            }
        }
        ans.push_back(maxstr);
        ans.push_back(to_string(maxans));
        return ans;
    }
};
