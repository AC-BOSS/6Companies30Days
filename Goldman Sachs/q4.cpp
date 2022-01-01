/* 
Question: Given a string, Your task is to  complete the function encode that returns the run length encoded string for the given string.
eg if the input string is “wwwwaaadexxxxxx”, then the function should return “w4a3d1e1x6″.
Question Link: https://practice.geeksforgeeks.org/problems/run-length-encoding/1
*/

#include <bits/stdc++.h>
using namespace std;

string encode(string src);    
 
int main() {
	
	int T;
	cin>>T;
	while(T--)
	{
		string str;
		cin>>str;
		
		cout<<encode(str)<<endl;
	}
	return 0;
}

string encode(string src)
{     
    char curr = src[0];
    int count = 1;
    string ans;
    for(int i=1; i<src.size(); ++i)
    {
        if(src[i] == curr)
            ++count;
        else
        {
            ans += curr;
            ans += to_string(count);
            count = 1;
            curr = src[i];
        }
    }
    ans += curr;
    ans += to_string(count);
    return ans;
}     
 
