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
    void solve(TreeNode* root,vector<vector<int>> &a){
        queue<TreeNode*> q;
        if(root!=nullptr) q.push(root);
        int i=1;
        while(!q.empty()){
            vector<int> v;
            int sz=q.size();
            for(int i=0;i<sz;i++){
                TreeNode* temp=q.front();
                q.pop();

                v.push_back(temp->val);
                if(temp->left!=nullptr) q.push(temp->left);
                if(temp->right!=nullptr) q.push(temp->right);
            }
            if(i%2==0){
                reverse(v.begin(),v.end());
                a.push_back(v);

            }
            else{
                a.push_back(v);
            }
            i++;
        }

    }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> v;
        solve(root,v);
        return v;
    }
};