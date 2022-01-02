// Question: Minimum Size Subarray Sum
// Question Link: https://leetcode.com/problems/minimum-size-subarray-sum

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int start=0, end = -1, sum=0, ans = INT_MAX;
        while(end < (int)nums.size() && start < (int)nums.size())
        {
            if(end < start)
            {
                end = start;
                sum += nums[end];
            }
            else if(sum >= target)
            {
                ans = min(ans, end-start+1);
                sum -= nums[start++];
            }
            else
            {
                if(end == nums.size()-1)
                    break;
                sum += nums[++end];
            }
            // cout<<sum<<' '<<start<<' '<<end<<endl;
        }
        return ans==INT_MAX?0:ans;
    }
};
