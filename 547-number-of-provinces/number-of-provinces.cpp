class Solution {
public:
    void dfs(vector<vector<int>>& graph,vector<int>& vis,int n,int m,int node){
        vis[node]=1;
        for(int i=0;i<m;i++){
            if(graph[node][i]==1 && !vis[i]){
                dfs(graph,vis,n,m,i);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        int m=isConnected[0].size();
        int ans=0;
        vector<int> vis(n,0);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                ans++;
                dfs(isConnected,vis,n,m,i);
            }
        }
        return ans;
    }
};