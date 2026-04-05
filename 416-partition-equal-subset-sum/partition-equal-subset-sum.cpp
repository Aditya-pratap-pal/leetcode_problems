class Solution {
public:
vector<vector<int>> dp;
bool func(vector<int> &v,int n,int totalsum,int sum,int idx){
    if(sum>totalsum)return false;
    if(sum==totalsum)return dp[idx][sum] = true;
    if(idx>=n || sum>totalsum)return dp[idx][sum] = false;
    if(dp[idx][sum]!=-1)return dp[idx][sum];
    return dp[idx][sum] = func(v,n,totalsum,sum+v[idx],idx+1)||func(v,n,totalsum,sum,idx+1);
}
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(),nums.end(),0);
        int target=sum/2;
        if(sum%2!=0)return false;
        dp.resize(nums.size()+1,vector<int>(target+1,-1));
        
        return func(nums,nums.size(),target,0,0);
    }
};