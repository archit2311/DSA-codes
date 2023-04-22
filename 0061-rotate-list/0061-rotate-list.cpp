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
       ListNode* rev(ListNode* head) {
        ListNode *prev=NULL;
        ListNode *curr=head;
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


    ListNode* rotateRight(ListNode* head, int k) {
        
        
        int n=0;
        ListNode *ptr=head;
        ListNode *prev=NULL;
        ListNode *curr=head;
        ListNode *head1=head;
        while(ptr!=NULL)
        {
            n++;
            prev=ptr;
            ptr=ptr->next;
        }
        if(n==0)return head;
        k=k%n;
        if(k==0)return head;
        int pos=n-k;
        int count=1;
       while(count!=pos)
        {
            curr=curr->next;
            count++;
        }
        ListNode *end1=curr->next;
        curr->next=NULL;
        ListNode *newhead1=rev(head);
        curr=newhead1;
        while(curr->next!=NULL)
        {
            curr=curr->next;
        }
        curr->next=end1;
        

        ListNode *newhead2=rev(curr->next);
        curr->next=newhead2;
        
        ListNode *ansNode=rev(newhead1);

        return ansNode;
    }
};