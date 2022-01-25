// Question: Capacity To Ship Packages Within D Days
// Question Link: https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/

class Solution {
public:
    int getDays(vector<int>& weights, int capacity)
    {
        int ans = 1, curr = 0;
        for(auto i:weights)
        {
            curr += i;
            if(curr > capacity)
            {
                ++ans;
                curr = i;
            }
        }
        return ans;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int l = *max_element(weights.begin(), weights.end()), r = 0, ans;
        for(int i=0; i<weights.size(); ++i)
            r += weights[i];
        int m;
        while(l <= r)
        {
            // cout<<l<<' '<<r<<endl;
            m = (l+r)/2;
            int day = getDays(weights, m);
            if(day > days)
                l = m+1;
            else if(l == r)
                return l;
            else
                r = m;
        }
        return m;
    }
};
