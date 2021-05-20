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

    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        TreeNode *endNode=new TreeNode(1001);
        q.push(endNode);
        vector<vector<int>> res;
        vector<int> temp;
        TreeNode *node;
        bool flag=true;
        while(!q.empty())
        {
            node=q.front();
            q.pop();
            if(node!=NULL)
            {
                if(node->val==1001)
                {
                    if(flag==true)
                        return res;
                    res.push_back(temp);
                    temp.clear();
                    q.push(endNode);
                    flag=true;
                    continue;
                }
                flag=false;
                temp.push_back(node->val);
                q.push(node->left);
                q.push(node->right);   
            }
        }
        
        return res;
    }
};