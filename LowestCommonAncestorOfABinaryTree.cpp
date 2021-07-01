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
    TreeNode *res=NULL;
    pair<bool,bool> traverse(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        if(res!=NULL) return make_pair(true,true);
        if(!root)return make_pair(false,false);
        pair<bool,bool> ans1=traverse(root->left,p,q);
        pair<bool,bool> ans2=traverse(root->right,p,q); 
        pair<bool,bool> ans=make_pair(ans1.first||ans2.first,ans1.second||ans2.second);
        if(root==p) ans.first=true;
        else if(root==q)ans.second=true;
        if(ans.first && ans.second && !res) res=root;
        return ans;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        traverse(root,p,q);
        return res;
    }
};
