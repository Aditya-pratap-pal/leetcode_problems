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
int maxSum=INT_MIN;
    int func(TreeNode* root){
        if(root==nullptr)return 0;
        int l=max(0,func(root->left));
        int r=max(0,func(root->right));
        maxSum=max(maxSum,root->val+l+r);
        
        return max(l,r)+root->val;
    }
    int maxPathSum(TreeNode* root) {
        int call = func(root);
        return max(root->val,maxSum);
    }
};