class Solution {
public:
    void func(vector<int> v,int n,int i,vector<int>& curr,vector<vector<int>> &ans){
        if(i>=n){
            ans.push_back(curr);
            return;
        }
        curr.push_back(v[i]);
        func(v,n,i+1,curr,ans);
        curr.pop_back();
        func(v,n,i+1,curr,ans);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> curr;
        func(nums,nums.size(),0,curr,ans);
        return ans;
    }
};