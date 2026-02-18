class Solution {
public:

    // int func(vector<vector<int>> &v,int n,int m,int i,int j,int dr,int dc,int emptyCell,int covered){
    //     if(i<0||j<0||i>=n||j>=m||v[i][j]==4||v[i][j]==-1)return 0;
    //     if(v[i][j]==2){
    //         if(covered-1==emptyCell){
    //             cout<<covered<<" "<<i<<" "<<j<<endl;
    //             return 1;
    //         }
    //         return 0;
    //     }
    //     v[i][j]=4;
    //     return func(v,n,m,i+1,j,dr,dc,emptyCell,covered+1)+
    //     func(v,n,m,i-1,j,dr,dc,emptyCell,covered+1)+
    //     func(v,n,m,i,j+1,dr,dc,emptyCell,covered+1)+
    //     func(v,n,m,i,j-1,dr,dc,emptyCell,covered+1);
    // }

    void func(vector<vector<int>> &v,int n,int m,int i,int j,int dr,int dc,int emptyCell,int covered,int &flag){
        if(i<0||j<0||i>=n||j>=m||v[i][j]==4||v[i][j]==-1)return ;
        if(v[i][j]==2){
            if(covered-1==emptyCell){
                cout<<covered<<" "<<i<<" "<<j<<endl;
                flag++;
            }
            return;
        }
        int temp=v[i][j];
        v[i][j]=4;
        func(v,n,m,i+1,j,dr,dc,emptyCell,covered+1,flag);
        func(v,n,m,i-1,j,dr,dc,emptyCell,covered+1,flag);
        func(v,n,m,i,j+1,dr,dc,emptyCell,covered+1,flag);
        func(v,n,m,i,j-1,dr,dc,emptyCell,covered+1,flag);
        v[i][j]=temp;
    }

    int uniquePathsIII(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        int emptyCell=0;
        int sr=0,sc=0,dr=0,dc=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0)emptyCell++;
                else if(grid[i][j]==1){
                    sr=i;
                    sc=j;
                }
                else if(grid[i][j]==2){
                    dr=i;
                    dc=j;
                }
            }
        }
        int ans = 0;
        func(grid,n,m,sr,sc,dr,dc,emptyCell,0,ans);
        return ans;
        // return func(grid,n,m,sr,sc,dr,dc,emptyCell,0);
    }
};