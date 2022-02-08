// Question: Power of numbers
// Question Link: https://practice.geeksforgeeks.org/problems/power-of-numbers-1587115620/1/?company[]=Walmart&company[]=Walmart&page=1&query=company[]Walmartpage1company[]Walmart#

class Solution{
    public:
    //You need to complete this fucntion
    const int MOD=1e9+7;
    long long power(long long int base,long long int ex)
    {
        if(ex == 0)
            return 1;
        if(ex == 1)
            return base;
        
        long long t = power(base, ex/2)%MOD;
        long long ans = t*t%MOD;
        if(ex%2==0)
            return ans;
        return base*ans%MOD;
    }
};
