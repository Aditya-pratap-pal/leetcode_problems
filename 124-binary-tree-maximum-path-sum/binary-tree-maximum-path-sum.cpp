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
    int func(TreeNode *root,int &maxi){
        if(root==nullptr)return 0;

        int l = func(root->left,maxi);
        int r = func(root->right,maxi);
        if(l<0)l=0;
        if(r<0)r=0;
        maxi = max(maxi,l+r+root->val);
        return max(l+root->val,r+root->val);

    }
    int maxPathSum(TreeNode* root) {
        // if(root==nullptr)return 0;
        int temp = INT_MIN;
        int ans = func(root,temp);
        return temp;
        
    }
};