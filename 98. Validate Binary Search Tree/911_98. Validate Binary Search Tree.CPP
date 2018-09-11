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
        vector<int> res;
        goThroughTree(root, res);
        
        int rL = res.size();
        for(int i = 0; i < rL-1; i++)
        {
            if(res[i] >= res[i+1])
            {
                return false;
            }
        }
        
        return true;
    }
    
    void goThroughTree(TreeNode *root, vector<int>& res)
    {
        if(!root)
        {
            return;
        }
        goThroughTree(root->left, res);
        res.push_back(root->val);
        goThroughTree(root->right, res);
        
        return;
    }
};