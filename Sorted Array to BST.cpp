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
    TreeNode *sortedArrayToBST(vector<int> &num) {
        if(num.size() == 0)
            return NULL;
        int mid = num.size() / 2;
        
        if(mid == 0)
            return new TreeNode(num[0]);
        
        TreeNode * root = new TreeNode(num[mid]);
        
        vector<int> left(num.begin(), num.begin() + mid);
        root->left  = sortedArrayToBST(left);
        
        vector<int> right(num.begin() + mid + 1, num.end());
        root->right = sortedArrayToBST(right);
        
        return root;
    }
};
