/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    int dfs(TreeNode *root,int maxi)
    {
        
       if(root==NULL)return 0;
        int a1=0,a2=0;
       if(root->left!=NULL && root->left->val >= maxi)
       {
          
           
            
            a1=1+dfs(root->left,root->left->val);
       }
       else
      a1= dfs(root->left,maxi);

       if(root->right!=NULL && root->right->val >= maxi)
       {
           
           
         
            a2=1+dfs(root->right,root->right->val);
       }
       else
       a2=dfs(root->right,maxi);

        return a1+a2;
    }

    int goodNodes(TreeNode* root) {
        if(root->left==NULL && root->right==NULL)
        return 1;
        int maxL=root->val;
       
        int ans=dfs(root,maxL);
        
        return 1+ans;

        
        
    }
};