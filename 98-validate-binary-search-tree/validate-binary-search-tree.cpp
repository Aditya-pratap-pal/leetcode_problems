class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return (valid(root->left,LONG_MIN,root->val) && valid(root->right,root->val,LONG_MAX));
        // return valid(root, LONG_MIN, LONG_MAX);        
    }

private:
    bool valid(TreeNode* node, long minimum, long maximum) {
        if (!node) return true;
        if ((node->val <= minimum || node->val >= maximum)) return false;
        return valid(node->left, minimum, node->val) && valid(node->right, node->val, maximum);
    }    
};