// Question: Smallest Range Covering Elements from K Lists
// Question Link: https://leetcode.com/problems/smallest-range-covering-elements-from-k-lists/

class Solution {
public:
    struct Node{
        int data, ind, arrind;
        Node(int data, int ind, int arrind)
        {
            this->data = data;
            this->ind = ind;
            this->arrind = arrind;
        }
    };
    struct cmp{
        bool operator()(Node* &x, Node* &y)
        {
            return x->data > y->data;
        }
    };
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int k = nums.size();
        
        priority_queue<Node*, vector<Node*>, cmp>pq;
        int maxi = INT_MIN;
        for(int i=0; i<k; ++i)
        {
            Node *e = new Node(nums[i][0], 0, i);
            pq.push(e);
            maxi = max(maxi, nums[i][0]);
        }
        vector<int>ans = {pq.top()->data, maxi};
        int diff = INT_MAX;
        while(!pq.empty())
        {
            Node* top = pq.top();
            pq.pop();
            int data = top->data;
            int ind = top->ind;
            int arrind = top->arrind;
            
            if(maxi - data < diff)
            {
                ans = {data, maxi};
                diff = maxi - data;
            }
            ++ind;
            if(ind >= nums[arrind].size())
                break;
            Node* e = new Node(nums[arrind][ind], ind, arrind); 
            pq.push(e);
            maxi = max(maxi, nums[arrind][ind]);
        }
        return ans;
    }
};
