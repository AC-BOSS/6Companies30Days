// Question: Divide two integers without using +,-,/ and long/unsigned
// Question Link: https://leetcode.com/problems/divide-two-integers/

class Solution {
public:
    int divide(int dividend, int divisor) {
        int q = 0;
        if(dividend == INT_MIN)
        {
            if(divisor == -1)
                return INT_MAX;
            if(divisor == 1)
                return INT_MIN;
            if(divisor == INT_MIN)
                return 1;
            q=1;
            dividend += abs(divisor);
        }
        if(divisor == INT_MIN)
            return 0;
        
        bool negative = (dividend<0)^(divisor<0);
        divisor = abs(divisor);
        dividend = abs(dividend);
    
        for(int i=31; i>=0; --i)
        {
            if(dividend>>i >= divisor)
            {
                dividend -= (divisor<<i);
                q += (1<<i);
            }
        }
        return negative?-q:q;
    }
};
