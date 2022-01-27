// Question: Compare Version Numbers
// Question Link: https://leetcode.com/problems/compare-version-numbers/

class Solution {
public:
    int compareVersion(string v1, string v2) {
        int i = 0, j = 0, n = v1.length(), m = v2.length();
        while(i<n && j<m)
        {
            string a, b;
            int flag1=0, flag2=0;
            while(i<n && v1[i] != '.')
            {
                if(flag1 || v1[i] != '0')
                {
                    flag1 = 1;
                    a += v1[i];
                }
                ++i;
            }
            while(j<m && v2[j] != '.')
            {
                if(flag2 || v2[j] != '0')
                {
                    flag2 = 1;
                    b += v2[j];
                }
                ++j;
            }
            if(a.size()<b.size() || ((a.size() == b.size()) && a<b))
                return -1;
            if(a.size()>b.size() || ((a.size() == b.size()) && a>b))
                return 1;
            if(v1[i] == '.' && v2[j] == '.')
            {
                ++i;
                ++j;
            }
        }
        
        while(i<n)
        {
            if(v1[i] != '.' && v1[i] != '0')
                return 1;
            ++i;
        }
        while(j<m)
        {
            if(v2[j] != '.' && v2[j] != '0')
                return -1;
            ++j;
        }
        return 0;
    }
};
