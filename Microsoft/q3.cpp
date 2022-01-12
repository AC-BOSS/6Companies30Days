// Question: Rotate Matrix 90 deg anti-clockwise
// Question Link: https://practice.geeksforgeeks.org/problems/rotate-by-90-degree0356/1/

void rotate(vector<vector<int> >& a)
{
    // Your code goes here
    int n=a.size();
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            swap(a[i][j],a[j][i]);
        }
    }
    for(int i=0;i<n/2;i++)
    {
        swap(a[i],a[n-1-i]);
    }
}
