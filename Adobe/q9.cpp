// Question: Next higher palindromic number using the same set of digits 
// Question Link: https://practice.geeksforgeeks.org/problems/next-higher-palindromic-number-using-the-same-set-of-digits5859/1

class Solution{
  public:
    bool isPal(string N)
    {
        int e = N.size()-1;
        int s = 0;
        while(s<=e)
        {
            if(N[s] != N[e])
                return false;
            ++s;
            --e;
        }
        return true;
    }
    string nextPerm(string nums,int mid)
    {
        int n = nums.size();
        int ind = -1;
        for(int i=mid-2; i>=0; --i)
        {
            if(nums[i] < nums[i+1])
            {
                ind = i;
                break;
            }
        }
        if(ind == -1)
            return "-1";
        
        for(int i=mid-1; i>ind; --i)
        {
            if(nums[i] > nums[ind])
            {
                swap(nums[ind], nums[i]);
                swap(nums[n-1-i], nums[n-1-ind]);
                break;
            }
        }
        reverse(nums.begin()+ind+1, nums.begin()+mid);
        if(n&1)
        {
            reverse(nums.begin()+mid+1, nums.end()-ind-1);
        }
        else
            reverse(nums.begin()+mid, nums.end()-ind-1);
        return nums;
    }
    string nextPalin(string N) { 
        int n = N.size();
        
        N = nextPerm(N, n/2);
        return N;
    }
};
