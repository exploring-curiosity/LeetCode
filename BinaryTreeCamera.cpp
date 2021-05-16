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
    int camera=0;
    void traverse(TreeNode* root,TreeNode* parent,TreeNode* grandparent)
    {
        if(root->left==NULL and root->right==NULL)
        {
            // check if node is monitored
                //set parent as camera (2)
                //set grandparent as monitored (1)
                //set parents children as monitored (1)
                //increment camera
            if(root->val==0)
            {
                if(parent==NULL)
                {
                    root->val=2;
                    camera+=1;
                }
                else
                {
                    parent->val=2;
                    camera+=1;
                    if(parent->left!=NULL)
                    {
                        parent->left->val=1;
                    }
                    if(parent->right!=NULL)
                    { 
                        parent->right->val=1;
                    }
                    if(grandparent!=NULL)
                    {
                        grandparent->val=1;
                    }
                }
            }
        }
        if(root->left!=NULL)
            traverse(root->left,root,parent);
        if(root->right!=NULL)
            traverse(root->right,root,parent);
        //check if value in root is 0.
            //set parent as camera (2)
            //set grandparent as monitored (1)
            //set parents children as monitored (1)
            //increment camera
        if(root->val==0)
        {
            if(parent==NULL)
            {
                root->val=2;
                camera+=1;
            }
            else
            {
                parent->val=2;
                camera+=1;
                if(parent->left!=NULL)
                {
                    parent->left->val=1;
                }
                if(parent->right!=NULL)
                { 
                    parent->right->val=1;
                }
                if(grandparent!=NULL)
                {
                    grandparent->val=1;
                }
            }
        }
    }
    int minCameraCover(TreeNode* root) {
        traverse(root,NULL,NULL);
        return camera; 
    }
};