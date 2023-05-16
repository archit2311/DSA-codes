/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        
        int n=0;
        int k1=k;
        ListNode *ptr=head;
        ListNode *curr1=head;
        ListNode *curr2=head;
        while(ptr!=NULL)
        {
            n++;
            ptr=ptr->next;
        }
        int k2=n-k;

        //if(n==k)return head;

        while(k1>1)
        {
            curr1=curr1->next;
            k1--;
        }
        
        while(k2>0)
        {
            curr2=curr2->next;
            k2--;
        }

        int temp=curr1->val;
        curr1->val=curr2->val;
        curr2->val=temp;

        return head;


    }
};