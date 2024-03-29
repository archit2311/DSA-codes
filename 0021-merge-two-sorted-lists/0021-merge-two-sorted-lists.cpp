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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

        if(list1==NULL)return list2;
        if(list2==NULL)return list1;
        ListNode *ptr=NULL;
        
        if(list1->val<=list2->val)
        {
            ptr=list1;
            list1=list1->next;
        }
        else{
            ptr=list2;
            list2=list2->next;
        }
        ListNode *curr=ptr;

        while(list1!=NULL && list2!=NULL)
        {
            if(list1->val<=list2->val)
            {
                curr->next=list1;
                list1=list1->next;
            }
            else
            {
                 curr->next=list2;
                list2=list2->next;
            }
            curr=curr->next;
        }

        //remaining elements

        if(list1!=NULL)
        curr->next=list1;
        if(list2!=NULL)
        curr->next=list2;

        return ptr;
























        // if(list1==NULL)return list2;
        // if(list2==NULL)return list1;
        // ListNode *list3=NULL;

        // if(list1->val<=list2->val)
        // {
        //     list3=list1;
        //     list3->next=mergeTwoLists(list1->next,list2);
        // }
        // else
        // {
        //     list3=list2;
        //     list3->next=mergeTwoLists(list1,list2->next);
        // }
        // return list3;

        

    }
};