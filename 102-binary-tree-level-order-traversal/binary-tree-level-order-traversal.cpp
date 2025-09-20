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
    vector<vector<int>> func(TreeNode* root){
        // temp.push_back(root->val);
        vector<vector<int>> v;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            vector<int> temp;
            int sz=q.size();
            for(int i=0;i<sz;i++){
                TreeNode* cNode=q.front();
                q.pop();
                if(cNode!=nullptr)temp.push_back(cNode->val);
                if(cNode!=nullptr&&cNode->left!=nullptr) q.push(cNode->left);
                if(cNode!=nullptr&&cNode->right!=nullptr) q.push(cNode->right);
            }
            if(temp.size()!=0)v.push_back(temp);
        }
        return v;
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        return func(root);
    }
};