class Solution {
public:
    void dfs(vector<vector<int>>& grid,vector<vector<int>>& vis,int n,int m,int i,int j){
        vis[i][j]=1;
        int x[4]={0,1,0,-1};
        int y[4]={1,0,-1,0};
        for(int k=0;k<4;k++){
            int ni=i+x[k];
            int nj=j+y[k];
            if(ni>=0 && ni<n && nj>=0 && nj<m && !vis[ni][nj] && grid[ni][nj]==1){
                dfs(grid,vis,n,m,ni,nj);
            }
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
         int n=grid.size();
         int m=grid[0].size();
         vector<vector<int>> vis(n,vector<int> (m,0));
         for(int i=0;i<n;i++){
            if(grid[i][0]==1){
                dfs(grid,vis,n,m,i,0);
            }
            if(grid[i][m-1]==1){
                dfs(grid,vis,n,m,i,m-1);
            }
         }
         for(int i=0;i<m;i++){
            if(grid[0][i]==1){
                dfs(grid,vis,n,m,0,i);
            }
            if(grid[n-1][i]==1){
                dfs(grid,vis,n,m,n-1,i);
            }
         }
         int cnt=0;
         for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1 && vis[i][j]==0)cnt++;
            }
         }
         return cnt;
    }
};