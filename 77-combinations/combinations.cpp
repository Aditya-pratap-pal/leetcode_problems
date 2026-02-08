class Solution {
public:
    void func(vector<vector<int>>& ans,vector<int> &currVec,int nn,int kk, int n,int k){
        if(nn>n)return;
        if(kk>=k){
            ans.push_back(currVec);
            return;
        }
        for(int i=1;i<=n;i++){
            currVec.push_back(nn+i);
            func(ans,currVec,nn+i,kk+1,n,k);
            currVec.pop_back();
            // kk--;
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> curr;
        func(ans,curr,0,0,n,k);
        return ans;
    }
};