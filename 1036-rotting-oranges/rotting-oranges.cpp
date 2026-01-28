class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2)q.push({i,j});
            }
        }
        int ans=0;
        // cout<<1<<" ";
        while(!q.empty()){
            // ans++;
            int size=q.size();
            while(size--){
                pair<int,int> p = q.front();
                int x[4]={0,1,0,-1};
                int y[4]={1,0,-1,0};
                for(int temp=0;temp<4;temp++){
                    int nx=p.first+x[temp],ny=p.second+y[temp];
                    if(nx<n && nx>=0 && ny<m && ny>=0 && grid[nx][ny]==1){
                        grid[nx][ny]=2;
                        q.push({nx,ny});
                    }
                }
                q.pop();
            }
                if(!q.empty())ans++;
        }
// cout<<2;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1)return -1;
            }
        }
        return ans;
    }
};