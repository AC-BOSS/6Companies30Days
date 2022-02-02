// Question: Split Array Largest Sum
// Question Link: https://leetcode.com/problems/split-array-largest-sum/

class Solution {
public:
    int subarrays(vector<int>&nums, int k)
    {
        int count = 1;
        int sum = 0;
        for(int i=0; i<nums.size(); ++i)
        {
            sum += nums[i];
            if(sum > k)
            {
                ++count;
                sum = nums[i];
            }
        }
        return count;
    }
    int splitArray(vector<int>& nums, int m) {
        int s = *max_element(nums.begin(), nums.end());
        int e = 0;
        for(auto i:nums)
            e += i;
        int ans;
        while(s<=e)
        {
            int mid = s - (s-e)/2;
            int k = subarrays(nums, mid);
            if(k > m)
            {
                s = mid + 1;
            }
            else
            {
                ans = mid;
                e = mid - 1;
            }
        }
        return ans;
    }
};
