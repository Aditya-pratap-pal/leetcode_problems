/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool func(TreeNode* left,TreeNode* right){
        if(left==nullptr && right==nullptr)return true;
        if(left==nullptr)return false;
        if(right==nullptr)return false;
        return (left->val==right->val)&&func(left->right,right->left)&&func(left->left,right->right);
    }
    bool isSymmetric(TreeNode* root) {
        return func(root->left,root->right);
    }
};