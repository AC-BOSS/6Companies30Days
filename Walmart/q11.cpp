// Question: Maximum Performance of a Team
// Question Link: https://leetcode.com/problems/maximum-performance-of-a-team/

class Solution {
public:
    static bool comparator(pair<int,int> a, pair<int,int> b)
    {
        if(a.first == b.first)
            return a.second > b.second;
        return a.first > b.first;
    }
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        vector<pair<long long,long long>>a;
        priority_queue<int, vector<int>, greater<int>>q;
        
        for(int i=0; i<n; ++i)
        {
            a.push_back({efficiency[i], speed[i]});
        }
        sort(a.begin(), a.end(), comparator);

        long long best = 0, sum=0;
        for(auto i:a)
        {
            sum += i.second;
            q.push(i.second);
            if(q.size() > k)
            {
                sum -= q.top();
                q.pop();
            }
            
            if(sum*i.first > best)
                best = sum*i.first;
            // cout<<sum<<' '<<best<<' '<<q.top()<<endl;
        }
        // cout<<best<<endl;
        // for(auto i:a)
        //     cout<<i.first<<' ';
        return best%1000000007;
    }
};
