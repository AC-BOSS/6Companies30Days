/*
Question: Given two strings str1 and str2. We say that str2 divides str1 if it's possible to concatenate multiple str2 to get str1. For example, ab divides abab. if str2 does not divide str1, return -1. Otherwise, return the smallest string
          str3 such that str3 divides both str1 and str2.
Question Link: https://leetcode.com/problems/greatest-common-divisor-of-strings/
*/
class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        if(str2.size() > str1.size())
        {
            string temp = str1;
            str1 = str2;
            str2 = temp;
        }
        // cout<<str1<<' '<<str2<<endl;
        string str = str2;
        while(str2.size() > 0)
        {
            string dummy = str2;
            while(dummy.size() < str.size())
            {
                dummy += str2;
            }
            if(dummy != str)
            {
                str2.pop_back();
                continue;
            }
            if(str1.find(str2, 0) != string::npos)
            {
                string temp = str2;
                while(temp.size() < str1.size())
                {
                    temp += str2;
                }
                if(temp == str1)
                    return str2;
            }
            str2.pop_back();
        }
        return "";
    }
};
