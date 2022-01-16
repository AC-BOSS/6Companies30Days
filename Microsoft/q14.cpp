// Question: Minimum steps to destination 
// Question Link: https://practice.geeksforgeeks.org/problems/minimum-number-of-steps-to-reach-a-given-number5234/1/

class Solution{
public:
    int minSteps(int target){
        // code here
        int sum = 0, step = 0;
        while (sum < target || (sum - target) % 2 != 0) {
            step++;
            sum += step;
        }
        return step;
    }
};
