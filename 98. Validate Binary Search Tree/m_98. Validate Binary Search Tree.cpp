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
        
        bool isRight = true;
        bool allRightBig = true;
        
        bool isLeft = true;
        bool allLeftSmall = true;
        
        if(root->right)
        {
            isRight = isValidBST(root->right);
            allRightBig = traverseRight(root->right, root->val);
        }
        if(root->left)
        {
            isLeft = isValidBST(root->left);
            allLeftSmall = traverseLeft(root->left, root->val);
        }
        
        
        return (isRight && isLeft) && (allRightBig && allLeftSmall);
    }
    
    bool traverseRight(TreeNode *root, int target)
    {
        if(!root)
        {
            return true;
        }
        
        
        bool leftSmall = traverseRight(root->left, target);
        bool rightBig = traverseRight(root->right, target);
        
        bool myRes = root->val > target;
        return ((leftSmall && rightBig) && myRes);
    }
    
    bool traverseLeft(TreeNode *root, int target)
    {
        if(!root)
        {
            return true;
        }
        
        bool leftSmall = traverseLeft(root->left, target);
        bool rightBig = traverseLeft(root->right, target);
        
        bool myRes = root->val < target;
        
        return ((leftSmall && rightBig) && myRes);
    }
};