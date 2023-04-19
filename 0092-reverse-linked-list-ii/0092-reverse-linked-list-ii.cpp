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

private:
      ListNode* reverseList(ListNode* head1) {
        ListNode *prev=NULL;
        ListNode *curr=head1;
        ListNode *temp;

        while(curr!=NULL)
        {
            temp=curr->next;
            curr->next=prev;
            prev=curr;
            curr=temp;

        }
        return prev;
    }
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        
        if(left==right)return head;
        int n=0,count=1;
        ListNode *current=head;
        ListNode *prev=NULL;

        while(count!=left)
        {
            prev=current;
            current=current->next;
            count++;
        }
        ListNode *start=current;

        while(count!=right)
        {
            current=current->next;
            count++;
        }

        ListNode *rest=current->next;
        current->next=NULL;

        ListNode *newhead=reverseList(start);
        if(prev!=NULL)
        prev->next=newhead;

        current=newhead;
       while(current->next!=NULL)
       {
           current=current->next;
       }

       current->next=rest;
       if(left==1)
       return newhead;
       else
       return head;
        


    }
};