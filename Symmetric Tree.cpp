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

    bool mirror(TreeNode * left, TreeNode * right)
    {
        if(left == NULL && right == NULL)
            return true;
        if(left != NULL && right == NULL)
            return false;
        if(left == NULL && right != NULL)
            return false;
        if(left != NULL && right != NULL) {
            
            if(left->val != right->val)
                return false;
        
            bool a = false, b = false;
            a = mirror(left->left, right->right);
            b = mirror(left->right, right->left);
            
            return a && b;
        }
    }
    
    bool isSymmetric(TreeNode *root) {
        if(root == NULL)
            return true;
        return mirror(root->left, root->right);
    }
};
