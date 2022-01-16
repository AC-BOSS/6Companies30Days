// Question: Find subarray with given sum
// Question Link: https://practice.geeksforgeeks.org/problems/subarray-with-given-sum-1587115621/1

class Solution
{
    public:
    //Function to find a continuous sub-array which adds up to a given number.
    vector<int> subarraySum(int arr[], int n, long long s)
    {
        int start = 0, end = 0;
        long long curr = arr[0];
        while(end < n)
        {
            if(curr == s)
            {
                return {start+1, end+1};
            }
            else if(curr < s)
            {
                if(end == n-1)
                    break;
                curr += arr[++end];
            }
            else
            {
                if(start == end)
                {
                    ++start;
                    ++end;
                    curr = arr[start];
                }
                else
                    curr -= arr[start++];
            }
        }
        return {-1};
    }
};
