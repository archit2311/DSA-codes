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
    ListNode* swapPairs(ListNode* head) {

        if(head==NULL || head->next==NULL)return head;

        ListNode *prev=head;
        ListNode *prev2=NULL;
        ListNode *curr=head->next;
        ListNode *newHead=head->next;
        
        while(curr!=NULL)
        {
            ListNode *ptr=curr->next;
            curr->next=prev;
            prev->next=ptr;
            if(prev2!=NULL)
            prev2->next=curr;
            prev2=prev;
            prev=ptr;
             if(ptr!=NULL)
            curr=ptr->next;
             else
             break;
        }

        return newHead;


    }
};