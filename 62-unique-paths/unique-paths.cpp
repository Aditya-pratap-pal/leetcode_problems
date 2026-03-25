class Solution {
public:
    // void func(int m,int n,int i,int j,int &ans){
    //     if(i<0||j<0||i>m||j>n)return;
    //     if(i==m && j==n){
    //         ans++;
    //         return;
    //     }
    //     func(m,n,i+1,j,ans);
    //     func(m,n,i,j+1,ans);
    // }
    int uniquePaths(int m, int n) {
        // int ans=0;
        // func(m,n,1,1,ans);
        // return ans;
        vector<vector<int>> dp(m,vector<int>(n,0));
        for(int i=0;i<n;i++){
            dp[0][i]=1;
        }
        for(int i=0;i<m;i++){
            dp[i][0]=1;
        }
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                dp[i][j]=dp[i-1][j]+dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }
};