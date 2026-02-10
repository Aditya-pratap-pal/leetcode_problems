class Solution {
public:
    void func(vector<int> &v,int n,vector<vector<int>> &ans,int i){
        if(i==n){
            ans.push_back(v);
            return;
        }
        for(int j=i;j<v.size();j++){
            swap(v[j],v[i]);
            func(v,n,ans,i+1);
            swap(v[j],v[i]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        func(nums,nums.size(),ans,0);
        return ans;
    }
};