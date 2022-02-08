// Question: Remove Colored Pieces if Both Neighbors are the Same Color
// Question Link: https://leetcode.com/problems/remove-colored-pieces-if-both-neighbors-are-the-same-color/

class Solution {
public:
    bool winnerOfGame(string colors) {
        int conA=0, conB=0, n=colors.size();
        for(int i=1; i<n-1; ++i)
        {
            if(colors[i]=='A' && colors[i-1]=='A' && colors[i+1]=='A')
                ++conA;
            else if(colors[i]=='B' && colors[i-1]=='B' && colors[i+1]=='B')
                ++conB;
        }
        return conA>conB;
    }
};
