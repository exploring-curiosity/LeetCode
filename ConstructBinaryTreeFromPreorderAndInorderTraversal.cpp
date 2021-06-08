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
    int nodeIndex=0;
    TreeNode* traverseLeft(vector<int> inorder,vector<int>& preorder)
    {
        nodeIndex++;
        if(nodeIndex>=preorder.size())
            return NULL;
        
        TreeNode* root=new TreeNode(preorder[nodeIndex]);
        vector<int>::iterator itr=find(inorder.begin(),inorder.end(),preorder[nodeIndex]);
        if(itr!=inorder.begin())
        {
            vector<int> left(inorder.begin(),itr);
            root->left=traverseLeft(left,preorder);
        }
        if((itr+1)!=inorder.end())  
        {
            vector<int> right(itr+1,inorder.end());
            root->right=traverseRight(right,preorder);
        }
        return root;
    }
    TreeNode* traverseRight(vector<int> inorder,vector<int>& preorder)
    {
        nodeIndex++;
        if(nodeIndex>=preorder.size())
            return NULL;
        
        TreeNode* root=new TreeNode(preorder[nodeIndex]);
        vector<int>::iterator itr=find(inorder.begin(),inorder.end(),preorder[nodeIndex]);
        if(itr!=inorder.begin())
        {
            vector<int> left(inorder.begin(),itr);
            root->left=traverseLeft(left,preorder);
        }
        if((itr+1)!=inorder.end())  
        {
            vector<int> right(itr+1,inorder.end());
            root->right=traverseRight(right,preorder);
        }
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n=preorder.size();
        TreeNode* root=new TreeNode(preorder[nodeIndex]);
        vector<int>::iterator itr=find(inorder.begin(),inorder.end(),preorder[nodeIndex]);
        if(itr!=inorder.begin())
        {
            vector<int> left(inorder.begin(),itr);
            root->left=traverseLeft(left,preorder);
        }
        if((itr+1)!=inorder.end())  
        {
            vector<int> right(itr+1,inorder.end());
            root->right=traverseRight(right,preorder);
        }
        
        return root;
    }
};