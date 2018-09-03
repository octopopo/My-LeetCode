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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root)
        {
            return NULL;
        }
        
        TreeNode *resL = lowestCommonAncestor(root->left, p, q);
        TreeNode *resR = lowestCommonAncestor(root->right, p, q);
        
        if(resL)
        {
            return resL;
        }
        if(resR)
        {
            return resR;
        }
        int searchRes = findDecendant(root, p->val, q->val);
        
        if(searchRes == 3)
        {
            return root;
        }
        
        
        return NULL;
    }
    
    int findDecendant(TreeNode *root, int p, int q)
    {
        if(!root)
        {
            return 0;
        }
        
        int lFind = findDecendant(root->left, p, q);
        int rFind = findDecendant(root->right, p, q);
        
        if(lFind == 3 || rFind == 3)
        {
            return 3;
        }
        else
        {
            if(lFind + rFind == 3)
            {
                return 3;
            }
            if(root->val == p)
            {
                if(lFind == 2 || rFind == 2)
                {
                    return 3;
                }
                return 1;
            }
            else if(root->val == q)
            {
                if(lFind == 1 || rFind == 1)
                {
                    return 3;
                }
                return 2;
            }
        }
        if(lFind != 0)
        {
            return lFind;
        }
        if(rFind != 0)
        {
            return rFind;
        }
        return 0;
    }
};