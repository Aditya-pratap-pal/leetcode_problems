class Solution {
public:
void func(vector<vector<int>>& v,int n,int m,int i,int j,int color,int original,vector<vector<int>>& vis){
    if(i>=n||j>=m||i<0||j<0||v[i][j]!=original||vis[i][j]==1)return;
    vis[i][j]=1;
    if(v[i][j]==original)v[i][j]=color;
    func(v,n,m,i+1,j,color,original,vis);
    func(v,n,m,i-1,j,color,original,vis);
    func(v,n,m,i,j+1,color,original,vis);
    func(v,n,m,i,j-1,color,original,vis);
}
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size(),m=image[0].size();
        vector<vector<int>> vis(n,vector<int> (m,0));
        func(image,image.size(),image[0].size(),sr,sc,color,image[sr][sc],vis);
        return image;
    }
};