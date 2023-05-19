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
    ListNode* reverseKGroup(ListNode* head, int k) {
        
        ListNode *dummy=new ListNode();
        dummy->next=head;
        ListNode *pre=dummy,*nex=dummy;
        ListNode*curr=head;
        int count=0;
        while(curr!=NULL)
        {
            count++;
            curr=curr->next;
        }

        while(count>=k)
        {
            curr=pre->next;
            nex=curr->next;
            for(int  i=0;i<k-1;i++)
            {
                curr->next=nex->next;
                nex->next=pre->next;
                pre->next=nex;
                nex=curr->next;

            }
            count=count-k;
            pre=curr;
        }

        return dummy->next;



    }
};