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
    bool isUnivalTree(TreeNode* root) {
        // invalid case
        if(!root)
            return true;
        
        int value = root->val;
        TreeNode* left = root->left;
        TreeNode* right = root->right;
        // special case
        if(!left && !right)
            return true;
        if(!left && right)
            if(right->val != value)
                return false;
        if(left && !right)
            if(left->val != value)
                return false;
        if(left && right)
            if(left->val != value || right->val != value)
                return false;
        // valid case
        bool check_left, check_right;
        check_left = isUnivalTree(left);
        check_right = isUnivalTree(right);
        return check_left && check_right;
    }
};
