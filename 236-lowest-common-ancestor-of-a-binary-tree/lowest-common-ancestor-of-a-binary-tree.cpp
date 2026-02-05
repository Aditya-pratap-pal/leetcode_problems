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
// bool flag=true;
//     TreeNode* func(TreeNode* root,TeeNode* p,TreeNode* q,TreeNode* &ans){
//         if(root==nullptr)return ;
//         if(root==p)return ;
//         if(root==q)return ;
//         lowestCommonAncestor(root->left,p,q);
//         lowestCommonAncestor(root->right,p,q);
//         if(left==nullptr && right==nullptr)return ;
//         if(left!=nullptr && right!=nullptr && flag){
//             flag=false;
//             ans=root;
//         }
//         if(left!=nullptr){
//             return;
//         }
//         return;

//     }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==nullptr)return root;
        if(root==p)return root;
        if(root==q)return root;
        TreeNode* left = lowestCommonAncestor(root->left,p,q);
        TreeNode* right = lowestCommonAncestor(root->right,p,q);
        if(left==nullptr && right ==nullptr)return nullptr;
        else if(left==nullptr)return right;
        else if(right==nullptr)return left;
        return root;
    }
};