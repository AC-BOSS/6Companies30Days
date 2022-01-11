// Question: Stock Span Problem
// Question Link: https://practice.geeksforgeeks.org/problems/stock-span-problem-1587115621/1

class Solution
{
    public:
    //Function to calculate the span of stockâ€™s price for all n days.
    vector <int> calculateSpan(int p[], int n)
    {
        vector<int>ans;
        stack<int>st;
        ans.push_back(1);
        st.push(0);
        
        for(int i=1; i<n; ++i)
        {
            int temp = 1;
            while(!st.empty() && p[i] >= p[st.top()])
            {
                temp += ans[st.top()];
                st.pop();
            }
            ans.push_back(temp);
            st.push(i);
        }
        return ans;
    }
};
