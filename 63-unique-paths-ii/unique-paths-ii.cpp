class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        vector<vector<int>> v=obstacleGrid;
        int n=v.size();
        int m=v[0].size();
        if(v[0][0]==1||v[n-1][m-1]==1)return 0;
        vector<vector<int>> dp(n,vector<int>(m,0));
        bool flag1=false,flag2=false;
        for(int i=0;i<n;i++){
            if(flag1){
                break;
            }
            dp[i][0]=1;
            if(v[i][0]==1){
                dp[i][0]=0;
                flag1=true;
            }
        }
        for(int i=0;i<m;i++){
            if(flag2){
                break;
            }
            dp[0][i]=1;
            if(v[0][i]==1){
                dp[0][i]=0;
                flag2=true;
            }
        }
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                dp[i][j] = dp[i-1][j]+dp[i][j-1];
                if(v[i][j]==1)dp[i][j]=0;
            }
        }
        return dp[n-1][m-1];
    }
};