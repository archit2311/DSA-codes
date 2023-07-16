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
    TreeNode* createMap(TreeNode *root,unordered_map<TreeNode* ,TreeNode*>&mp,int start)
    {
        TreeNode *res=NULL;
        
        queue<TreeNode*>q;
        q.push(root);
        if(root->val==start)
        res=root;

        while(!q.empty())
        {
            TreeNode *curr=q.front();
            q.pop();
            if(curr->val==start)
            res=curr;

            if(curr->left)
            {
                q.push(curr->left);
                mp[curr->left]=curr;
            }
            if(curr->right)
            {
                q.push(curr->right);
                mp[curr->right]=curr;
            }

        }
        return res;
    }


    int amountOfTime(TreeNode* root, int start) {
        unordered_map<TreeNode* ,TreeNode*>mp;
        TreeNode *target=createMap(root,mp,start);
        unordered_map<TreeNode*, bool>vis;
        queue<TreeNode*>q;
        q.push(target);
        vis[target]=true;
        int time=0;
        while(!q.empty())
        {
            bool flag=0;
            int size=q.size();
            for(int i=0;i<size;i++)
            {
                TreeNode *curr=q.front();
                q.pop();

                if(curr->left && !vis[curr->left])
                {
                    q.push(curr->left);
                    vis[curr->left]=true;
                    flag=1;
                }
                if(curr->right && !vis[curr->right])
                {
                    q.push(curr->right);
                    vis[curr->right]=true;
                    flag=1;
                }
                if(mp[curr] && !vis[mp[curr]])
                {
                    q.push(mp[curr]);
                    vis[mp[curr]]=true;
                    flag=1;
                }
            }
            if(flag==1)
            time++;

        }

        return time;

    
    }

};