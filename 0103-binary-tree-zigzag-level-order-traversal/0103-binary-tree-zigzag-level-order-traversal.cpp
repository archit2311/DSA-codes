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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        
        vector<vector<int>>ans;
        if(root==NULL)
        return ans;
        bool rev=false;
        queue<TreeNode *>q;
        q.push(root);

        while(!q.empty())
        {
                                                                       
            int size=q.size();
            vector<int>v;
            for(int i=0;i<size;i++){
            TreeNode *curr=q.front();
            q.pop();
            v.push_back(curr->val);
            
            if(curr->left!=NULL)
            q.push(curr->left);
            if(curr->right!=NULL)
            q.push(curr->right);

            }
            if(rev==false){
            ans.push_back(v);
            rev=!rev;
            }
            else{
                reverse(v.begin(),v.end());
                ans.push_back(v);
                rev=!rev;
            }


        }
    return ans;
    }

};