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
    /*
    void posttrav(TreeNode * root, vector<int>& s)
    {
        if(root != NULL){
            posttrav(root->left, s);
            posttrav(root->right, s);
            s.push_back(root->val);
        }
    }
    */
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> vec;
        TreeNode * temp = root;
        stack<TreeNode *> s1, s2;
        s1.push(root);
        while(!s1.empty())
        {
            temp = s1.top();
            s1.pop();
            s2.push(temp);
            s1.push(temp->left);
            s1.push(temp->right);
        }
        while(!s2.empty())
        {
            vec.push_back(s2.top());
            s2.pop();
        }
        return vec;
    }
};
