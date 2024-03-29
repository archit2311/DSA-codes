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
    int maxLevelSum(TreeNode* root) {
        
        int ans=INT_MIN;
        int level=0;
        int ansLevel;
        queue<TreeNode *>q;
        q.push(root);
        while(!q.empty())
        {
           int sum=0;
            int qsize=q.size();
            level++;
             
            while(qsize>0)
            {
                 TreeNode *curr=q.front();
                 q.pop();
                sum+=curr->val;
                 if(curr->left!=NULL)
                 q.push(curr->left);
                 if(curr->right!=NULL)
                 q.push(curr->right);

                 qsize--;
            }  
            if(ans<sum)
            {
                ans=sum;
                ansLevel=level;
            }
        }

        return ansLevel;
    }
};