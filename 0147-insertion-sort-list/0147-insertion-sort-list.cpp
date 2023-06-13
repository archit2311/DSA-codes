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
    ListNode* insertionSortList(ListNode* head) {
        if(head->next==NULL)
        return head;
        ListNode *curr=head->next;
        ListNode *prev1=head;
        while(curr!=NULL)
        {
            
            ListNode *curr2=head;
            ListNode *prev=NULL;
            int change=0;
            ListNode *temp=curr->next;
            while(curr2!=curr)
            {
                if(curr2->val>curr->val)
                {
                    change=1;
                    
                    if(prev==NULL)
                    {
                        curr->next=head;
                        head=curr;
                    }
                    else{
                        curr->next=prev->next;
                        prev->next=curr;
                    }
                    prev1->next=temp;
                    break;
                }
                prev=curr2;
                curr2=curr2->next;
            }
            
            if(change==0){
            prev1=curr;
            curr=curr->next;
            }
            else{
            curr=temp;
            }
        }
        return head;
    }
};