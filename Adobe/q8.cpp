// Question: Implement Atoi 
// Question Link: https://practice.geeksforgeeks.org/problems/implement-atoi/1

class Solution{
  public:
    /*You are required to complete this method */
    int atoi(string str) {
        int ans = 0, neg = 0;
        if(str[0] == '-')
        {
            neg = 1;
            str.erase(str.begin());
        }
        for(auto i:str)
        {
            int num = i-'0';
            if(num < 0 || num > 9)
                return -1;
            ans = ans*10 + i - '0';
        }
        if(neg)
            return -1*ans;
        return ans;
    }
};
