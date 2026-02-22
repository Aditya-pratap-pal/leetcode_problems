class Solution {
public:
vector<int> dp;
int step(int n){
    if(n==1||n==0)return dp[n]=1;
    if(dp[n]!=-1)return dp[n];
    return dp[n]=step(n-1)+step(n-2);
}
    int climbStairs(int n) {
        dp.resize(n+1,-1);
        return step(n);
    }
};