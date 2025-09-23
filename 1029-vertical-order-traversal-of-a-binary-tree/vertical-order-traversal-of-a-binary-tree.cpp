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
    void func(TreeNode* root,map< int, map<int,vector<int>> > &mp,int index,int level){
        if(root==nullptr)return;
        mp[index][level].push_back(root->val);
        func(root->left,mp,index-1,level+1);
        func(root->right,mp,index+1,level+1);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        map<int,map<int,vector<int>>> mp;
        func(root,mp,0,0);
        for(auto it:mp){
            vector<int> temp;
            for(auto i:it.second){
                vector<int> u=i.second;
                sort(u.begin(),u.end());
                for(auto j:u){
                    temp.push_back(j);
                }
            }

            // sort(temp.begin(),temp.end());
            ans.push_back(temp);
            
        }
        return ans;
    }
};