class Solution {
public:
    void func(vector<int>& v,int n,int target,vector<vector<int>> &ans,vector<int> &curr,int i,int sum){
        if(sum==target){
            ans.push_back(curr);
            return;
        }
        if(sum>target || i>=n)return;
        curr.push_back(v[i]);
        func(v,n,target,ans,curr,i,sum+v[i]);
        curr.pop_back();
        func(v,n,target,ans,curr,i+1,sum);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> curr;
        func(candidates,candidates.size(),target,ans,curr,0,0);
        return ans;
    }
};