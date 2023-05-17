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
    int pairSum(ListNode* head) {
        int ans=INT_MIN;
        vector<int>v;
        int n=0;
        ListNode *ptr=head;

        while(ptr!=NULL)
        {
            n++;
            v.push_back(ptr->val);
            ptr=ptr->next;
        }

        for(int i=0;i<=n/2-1;i++)
        {
            int res=v[i]+v[n-1-i];
            ans=max(ans,res);
        }
        return ans;
    }
};