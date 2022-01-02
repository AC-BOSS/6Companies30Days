// Question: Decode the String
// Question Link: https://practice.geeksforgeeks.org/problems/decode-the-string2444/1

#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    string decodedString(string s) {
        int i=0;
        stack<int>k;
        stack<string>str;
        string curr;
        while(i < s.size())
        {
            if(isdigit(s[i]))
            {
                int num = 0;
                while(isdigit(s[i]))
                {
                    num = num*10 + (s[i] - '0');
                    ++i;
                }
                k.push(num);
            }
            else if(s[i] == ']')
            {
                string temp = curr;
                for(int j=0; j<k.top()-1; ++j)
                {
                    curr += temp;
                }
                k.pop();
                string top = str.top();
                str.pop();
                top += curr;
                curr = top;
                ++i;
            }
            else if(s[i] == '[')
            {
                str.push(curr);
                curr = "";
                ++i;
            }
            else
            {
                curr += s[i];
                ++i;
            }
        }
        return curr;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        
        Solution ob;
        cout<<ob.decodedString(s)<<"\n";
    }
    return 0;
}  // } Driver Code Ends
