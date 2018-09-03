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
    bool isValidBST(TreeNode* root) {
        if(!root)
        {
            return true;
        }
        vector<int> inorderTree;
        inorder(root, inorderTree);
        int iL = inorderTree.size();
        
        for(int i = 0; i < iL - 1; i++)
        {
            if(inorderTree[i] >= inorderTree[i+1])
            {
                return false;
            }
        }
        
        return true;
        
    }
    
    void inorder(TreeNode *root, vector<int> &inTree)
    {
        if(!root)
        {
            return;
        }
        inorder(root->left, inTree);
        inTree.push_back(root->val);
        inorder(root->right, inTree);
        return;
    }
};