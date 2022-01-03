// Question: Given a pattern containing only I's and D's. I for increasing and D for decreasing. Devise an algorithm to print the minimum number following that pattern.
// Question Link: https://practice.geeksforgeeks.org/problems/number-following-a-pattern3126/1

#include<bits/stdc++.h> 
using namespace std; 

class Solution{   
public:
    string printMinNumberForPattern(string S){
        stack<string>st;
        string ans;
        for(int i=0; i<=S.length(); ++i)
        {
            st.push(to_string(i+1));
            if(S[i] == 'I' || i==S.size())
            {
                while(!st.empty())
                {
                    ans += st.top();
                    st.pop();
                }
            }
        }
        return ans;
    }
};


// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string S;
        cin >> S;
        Solution ob;
        cout << ob.printMinNumberForPattern(S) << endl;
    }
    return 0; 
} 
  // } Driver Code Ends
