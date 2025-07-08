class Solution {
public:
    void dfs(vector<vector<char>> &board,vector<vector<int>> &vis,int n,int m,int i,int j){
        vis[i][j]=1;
        int x[4]={-1,0,1,0};
        int y[4]={0,-1,0,1};
         for(int k=0;k<4;k++){
            int ni=i+x[k];
            int nj=j+y[k];
            if(ni>=0 && ni<n && nj>=0 && nj<m && !vis[ni][nj] && board[ni][nj]=='O'){
                // vis[ni][nj]=1;
                dfs(board,vis,n,m,ni,nj);
            }
         }
    }
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int i=0;i<m;i++){
            if(board[0][i]=='O')
                dfs(board,vis,n,m,0,i);
            if(board[n-1][i]=='O')
                dfs(board,vis,n,m,n-1,i);
        }
        for(int i=0;i<n;i++){
            if(board[i][0]=='O')
                dfs(board,vis,n,m,i,0);
            if(board[i][m-1]=='O')
                dfs(board,vis,n,m,i,m-1);
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='O' && vis[i][j]==0){
                    board[i][j]='X';
                }
            }
        }
    }
};