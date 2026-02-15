class Solution {
public:
    void func(vector<int>& nums,int n,int i,int prev,vector<int> &curr,vector<vector<int>> &ans){
        if(i>n)return;
        if(i==n){
            if(curr.size()>1)ans.push_back(curr);
            return;
        }
        if(nums[i]>=prev){
            curr.push_back(nums[i]);
            func(nums,n,i+1,nums[i],curr,ans);
            curr.pop_back();
        }
        func(nums,n,i+1,prev,curr,ans);
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<int> curr;
        vector<vector<int>> ans,final;
        // for(int i=1;i<nums.size();i++){
            func(nums,nums.size(),0,-101,curr,ans);
        // }
        set<vector<int>> s;
        for(int i=0;i<ans.size();i++){
            s.insert(ans[i]);
        }
        for(auto it:s){
            final.push_back(it);
        }
        return final;
    }
};