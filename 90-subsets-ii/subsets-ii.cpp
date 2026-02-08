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
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans,final;
        vector<int> curr;
        func(nums,nums.size(),0,curr,ans);
        set<vector<int>> s;
        for(int i=0;i<ans.size();i++){
            sort(ans[i].begin(),ans[i].end());
            s.insert(ans[i]);
        }
        for(auto it:s){
            final.push_back(it);
        }
        return final;
    }
};