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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(!root)
        {
            return res;
        }
        
        queue<TreeNode*> levelNode;
        
        levelNode.push(root);
        TreeNode *tempN;
        while(!levelNode.empty())
        {
            int nodeCount = levelNode.size();
            vector<int> tempV;
            for(int i = 0; i < nodeCount; i++)
            {
                tempN = levelNode.front();
                levelNode.pop();
                tempV.push_back(tempN->val);
                if(tempN->left)
                {
                    levelNode.push(tempN->left);
                }
                if(tempN->right)
                {
                    levelNode.push(tempN->right);
                }
            }
            res.push_back(tempV);
        }
        
        return res;
    }
};