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
int diameter=0;
    int length(TreeNode* root){
        if(root==nullptr)return 0;
        int l=length(root->left)+1;
        int r=length(root->right)+1;
        diameter=max(diameter,l+r);
        return max(l,r);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int len=length(root);
        return diameter-2;
    }
};