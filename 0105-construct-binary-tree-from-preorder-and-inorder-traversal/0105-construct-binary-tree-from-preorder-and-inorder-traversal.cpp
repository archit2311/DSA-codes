
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

    TreeNode *solve(vector<int>& preorder, vector<int>& inorder, int &index,  map<int,int>&mp,int start, int end,int n)
    {
       if(index>=n||start>end )return NULL;
        
        int ele = preorder[index++]; 
        TreeNode *root=new TreeNode(ele);
         int pos=mp[ele];
        //recursion
        root->left= solve(preorder,inorder,index,mp,start,pos-1,n);
        root->right=solve(preorder,inorder,index,mp,pos+1,end,n);

    return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        int n=preorder.size();
       map<int,int>mp;
        for(int i=0;i<n;i++)
        {
            mp[inorder[i]]=i;
        }
        int preIdx=0;
        TreeNode *ans=solve(preorder,inorder,preIdx,mp,0,n-1,n);
       return ans;
    }
};