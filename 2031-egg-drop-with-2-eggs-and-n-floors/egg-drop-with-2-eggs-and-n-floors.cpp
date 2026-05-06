class Solution {
public:
    int solve(int floor,int egg,vector<vector<int>>& dp){
        if(floor==0 || floor==1)return floor;
        if(egg==1)return floor;
        int ans=1e8;
        if(dp[floor][egg]!=-1)return dp[floor][egg];
        for(int k=1;k<=floor;k++){
            int breakegg = solve(k-1,egg-1,dp);
            int breaknot = solve(floor-k,egg,dp);
            int other = 1+max(breakegg,breaknot);
            ans  = min(ans,other);
        }
        return dp[floor][egg] = ans;
    }
    int twoEggDrop(int n) {
        vector<vector<int>> dp(n+1,vector<int>(3,-1));
        return solve(n,2,dp);
    }
};