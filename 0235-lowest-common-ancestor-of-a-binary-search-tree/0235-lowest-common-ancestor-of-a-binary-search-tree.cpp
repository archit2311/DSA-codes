/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        if(root==NULL)
        return root;

        if(root==p)
        return root;

        if(root==q)
        return root;
        TreeNode *lca1=NULL;
        TreeNode *lca2=NULL;
        if(root->val>p->val && root->val>q->val){
        lca1=lowestCommonAncestor(root->left,p,q);
        }
        else if(root->val<p->val && root->val<q->val){
        lca2=lowestCommonAncestor(root->right,p,q);
        }
        else
        return root;

        if(lca1!=NULL && lca2!=NULL)
        return root;
        else if(lca1!=NULL && lca2==NULL)
        return lca1;
        else
        return lca2;


    }};





