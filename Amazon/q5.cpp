// Question: Phone directory
// Question Link: https://practice.geeksforgeeks.org/problems/phone-directory4628/1

class Solution{
public:
    vector<vector<string>> displayContacts(int n, string contact[], string s)
    {
        set<string>st;
        vector<vector<string>>ans;
        for(int i=0; i<n; ++i)
            st.insert(contact[i]);
        for(int i=1; i<=s.size(); ++i)
        {
            vector<string>temp;
            string sub = s.substr(0, i);
            for(auto it=st.begin(); it != st.end(); ++it)
            {
                // cout<<*it<<' ';
                if((*it).substr(0, sub.size()) == sub)
                    temp.push_back(*it);
                //this portion was giving runtime error
                // else
                //     st.erase(it);
                // --it;
              
            }
            if(temp.empty())
                ans.push_back({"0"});
            else
                ans.push_back(temp);
        }
        return ans;
    }
};
