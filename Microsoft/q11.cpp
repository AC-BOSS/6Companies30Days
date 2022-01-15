// Question: Generate Binary Numbers 
// Question Link: https://practice.geeksforgeeks.org/problems/generate-binary-numbers-1587115620/1/

string toBinary(int n)
{
    string ans="";
    while(n>0)
    {
        ans=to_string(n%2)+ans;
        n=n/2;
    }
    return ans;
}
vector<string> generate(int n)
{
	// Your code here
	vector<string>ans;
	for(int i=1;i<=n;i++)
	{
	    ans.push_back(toBinary(i));
	}
	return ans;
}
