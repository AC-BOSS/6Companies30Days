// Question: Delete N nodes after M nodes
// Question Link: https://practice.geeksforgeeks.org/problems/delete-n-nodes-after-m-nodes-of-a-linked-list/1/

class Solution
{
    public:
    void linkdelete(struct Node  *head, int m, int n)
    {
        if(n==0)
            return;
        if(m == 0)
        {
            head = NULL;
            return;
        }
        struct Node *temp = head;
        while(temp != NULL)
        {
            for(int i=0; i<m-1; ++i)
            {
                temp = temp->next;
                if(temp == NULL)
                    return;
            }
            struct Node *temp2 = temp->next;
            if(temp2 == NULL)
                return;
            for(int i=0; i<n; ++i)
            {
                temp2 = temp2->next;
                if(temp2 == NULL)
                    break;
            }
            temp->next = temp2;
            temp = temp2;
        }
    }
};
