// Question: Find the Kth Largest Integer in the Array
// Question Link: https://leetcode.com/problems/find-the-kth-largest-integer-in-the-array/

class Solution {
public:
    static bool comparator(string a, string b)
    {
        if(a.length() > b.length())
            return true;
        else if(a.length() < b.length())
            return false;
        for(int i=0; i<a.length(); ++i)
        {
            if(a[i] != b[i])
                return a[i]>b[i];
        }
        return false;
    }
    string kthLargestNumber(vector<string>& nums, int k) {
        sort(nums.begin(), nums.end(), comparator);
        return nums[k-1];
    }
};
