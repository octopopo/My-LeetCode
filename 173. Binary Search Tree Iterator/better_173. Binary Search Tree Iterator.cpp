/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class BSTIterator {
public:
    stack<int> m_stack;
    
    BSTIterator(TreeNode *root) {
        if(root){
            GoThroughTree(root);
        }
    }
    
    void GoThroughTree(TreeNode *root)
    {
        if(!root)
        {
            return;
        }
        GoThroughTree(root->right);
        m_stack.push(root->val);
        GoThroughTree(root->left);
        return;
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !m_stack.empty();
    }

    /** @return the next smallest number */
    int next() {
        if(!m_stack.empty())
        {
            int tTop = m_stack.top();
            m_stack.pop();
            return tTop;
        }
        return 0;
    }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */