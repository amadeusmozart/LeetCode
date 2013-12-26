/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int maxDepth(TreeNode *root) {
        if(root == NULL)
            return 0;
        
        int lefth = maxDepth(root->left);
        int righth = maxDepth(root->right);
    
        if(lefth > righth)
            return lefth + 1;
        else
            return righth + 1;
    }
};
