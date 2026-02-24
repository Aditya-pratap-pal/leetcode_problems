class Solution {
public:
    vector<int> dp;
    int money(vector<int>& v,int n,int i){
        if(i>=n)return dp[i] = 0;
        if(dp[i]!=-1) return dp[i];
        int next = v[i]+money(v,n,i+2);
        int nextToNext = money(v,n,i+1);
        return dp[i] = max(next,nextToNext);
    }
    int rob(vector<int>& nums) {
        dp.resize(nums.size()+2,-1);
        int idx1 = money(nums,nums.size(),0);
        int idx2 = money(nums,nums.size(),1);
        return max(idx1,idx2);
    }
};