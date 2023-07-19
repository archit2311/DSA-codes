//{ Driver Code Starts
// driver

#include <bits/stdc++.h>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}


// } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    
     struct Node* reverseList(struct Node* head) {
        struct Node *prev=NULL;
        struct Node *curr=head;
        struct Node *temp;

        while(curr!=NULL)
        {
            temp=curr->next;
            curr->next=prev;
            prev=curr;
            
            curr=temp;

        }
        return prev;
    }
    
    
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
       //reverseing the two lists
       struct Node *l1= reverseList(first);
       struct Node *l2= reverseList(second);
       
       
        struct Node *dummy=new Node(NULL);
       struct Node *temp=dummy;
        int carry=0;
        while(l1!=NULL || l2!=NULL ||carry)
        {
            int sum=0;
            
            if(l1!=NULL)
            {
                sum+=l1->data;
                l1=l1->next;
            }

            if(l2!=NULL)
            {
                sum+=l2->data;
                l2=l2->next;
            }
            sum+=carry;
            carry=sum/10;
            struct Node *node=new struct Node(sum%10);
            temp->next=node;
            temp=temp->next;
            
        }
        struct Node *ans=reverseList(dummy->next);
        return ans;
        
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* first = buildList(n);
        
        cin>>m;
        Node* second = buildList(m);
        Solution ob;
        Node* res = ob.addTwoLists(first,second);
        printList(res);
    }
    return 0;
}

// } Driver Code Ends