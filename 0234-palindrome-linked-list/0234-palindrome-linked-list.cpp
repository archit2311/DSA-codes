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
    ListNode* reverse(ListNode *head)
    {
        if(head->next==NULL)
        return head;
        ListNode *curr=head;
        ListNode *temp;
        ListNode *prev=NULL;

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
    bool isPalindrome(ListNode* head) {
        
        if(head->next==NULL)return true;
        if(head->next!=NULL && head->next->next==NULL)
        {
            return(head->val == head->next->val);
        }
        //finding middle
        ListNode *slow=head;
        ListNode *fast=head;       
        ListNode *curr=head;

        while(fast!=NULL && fast->next!=NULL && fast->next->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
        }

        ListNode *ptr=reverse(slow->next);
        cout<<ptr->val;
        slow->next=ptr;

        while(ptr!=NULL && curr!=NULL)
        {
            if(curr->val != ptr->val)
            return false;
            
            curr=curr->next;
            ptr=ptr->next;
        }
        return true;


    }
};