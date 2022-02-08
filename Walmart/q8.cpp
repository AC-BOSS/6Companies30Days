// Question: Maximum Height Tree
// Question Link: https://practice.geeksforgeeks.org/problems/maximum-height-tree4803/1/?page=2&company[]=Walmart&query=page2company[]Walmart

class Solution{
public:
    int height(int n){
        return (-1 + (int)sqrt(1+8*n))/2;     //Quadratic Formula or Sri Dharacharya Formula
    }
};
