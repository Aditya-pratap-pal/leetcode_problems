class Solution {
public:
void func(int k,int sum,vector<vector<int>> &ans,vector<int> &curr,int kk,int currSum,int i){
    if(kk>k || i>9 || currSum>sum)return;
    if(kk==k && currSum!=sum)return;
    if(currSum==sum && kk==k){
        ans.push_back(curr);
        return;
    }
    for(int j=i+1;j<=9;j++){
        curr.push_back(j);
        func(k,sum,ans,curr,kk+1,currSum+j,j);
        curr.pop_back();
        func(k,sum,ans,curr,kk,currSum,j);
    }
}
    vector<vector<int>> combinationSum3(int k, int n) {
        if(n>45)return {};
        vector<vector<int>> ans,final;
        vector<int> curr;
        func(k,n,ans,curr,0,0,0);
        set<vector<int>> s;
        for(auto it: ans){
            s.insert(it);
        }
        for(auto it: s){
            final.push_back(it);
        }
        return final;
    }
};