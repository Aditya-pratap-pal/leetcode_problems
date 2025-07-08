class Solution {
public:
    void bfs(vector<vector<char>> &grid,vector<vector<int>>& vis,int n,int m,int i,int j){
        vis[i][j]=1;
        int x[4]={0,-1,0,1};
        int y[4]={-1,0,1,0};
        for(int k=0;k<4;k++){
            int ni=i+x[k];
            int nj=j+y[k];
            if(ni>=0 && ni<n && nj>=0 && nj<m && grid[ni][nj]=='1' && !vis[ni][nj]){
                bfs(grid,vis,n,m,ni,nj);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int land=0,n=grid.size(),m=grid[0].size();
        vector<vector<int>> vis(n,vector<int> (m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1' && !vis[i][j]){
                    land++;
                    bfs(grid,vis,n,m,i,j);
                }
            }
        }
        return land;
    }
};