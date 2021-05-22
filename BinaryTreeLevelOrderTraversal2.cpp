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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        queue<TreeNode*> q;
        stack<TreeNode*> s;
        q.push(root);
        
        TreeNode *endNode=new TreeNode(1001);
        q.push(endNode);
        s.push(endNode);
        s.push(root);
        s.push(endNode);
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
                        break;
                    q.push(endNode);
                    s.push(endNode);
                    flag=true;
                    continue;
                }
                flag=false;
                q.push(node->left);
                q.push(node->right);
                s.push(node->left);
                s.push(node->right);
            }
        }
        while(!s.empty()){
            node = s.top(); 
            s.pop();
            if(node!=NULL)
            {
                cout<<node->val<<",";
                if(node->val==1001)
                {
                    if(temp.size()!=0)
                    res.push_back(temp);
                    temp.clear();
                    continue; 
                }
                temp.insert(temp.begin(),node->val);
            }
            
        }
        return res;
    }
};