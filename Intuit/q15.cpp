// Question: Koko Eating Bananas
// Question Link: https://leetcode.com/problems/koko-eating-bananas/

class Solution {
public:
    int getHours(vector<int>&piles, int k)
    {
        int ans = 0;
        for(auto i:piles)
        {
            ans += i/k + (i%k>0?1:0);
        }
        return ans;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int s = 1, e=*max_element(piles.begin(), piles.end());
        int k;
        while(s <= e)
        {
            int m = s - (s-e)/2;
            int hours = getHours(piles, m);
            if(hours <=h)
            {
                k = m;
                e = m-1;
            }
            else
            {
                s = m+1;
            }
        }
        return k;
    }
};
