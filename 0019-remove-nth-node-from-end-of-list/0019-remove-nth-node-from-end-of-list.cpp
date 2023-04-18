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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        int len=0;
        ListNode *ptr=head;

        while(ptr!=NULL)
        {
            len++;
            ptr=ptr->next;
        }

        if(n==1 && head->next==NULL)return NULL;
        
        
        ListNode *curr=head;
        int k=len-n;
        if(k==0)
        head=head->next;

        while(curr!=NULL && k>1)
        {
            curr=curr->next;
            k--;
        }

        curr->next=curr->next->next;
        return head;
    }
};