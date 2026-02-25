class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        // vector<vector<int>> v=heights;
        int n=heights.size();
        int m=heights[0].size();
        vector<vector<int>> dis(n,vector<int>(m,INT_MAX));

        priority_queue <pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<>> pq;
        pq.push({0,{0,0}});
        dis[0][0]=0;

        vector<int> r = {-1,0,1,0};
        vector<int> c = {0,1,0,-1};

        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();

            int step = it.first;
            int rr=it.second.first;
            int cc=it.second.second;

            if(rr==n-1 && cc==m-1)return step;

            for(int i=0;i<4;i++){
                int nr=rr+r[i];
                int nc=cc+c[i];
                    if(nr>=0 && nc>=0 && nr<n && nc<m ){
                        int newStep = max(step,abs(heights[rr][cc]-heights[nr][nc]));
                    
                    if(newStep<dis[nr][nc]){
                        dis[nr][nc]=newStep;
                        pq.push({newStep,{nr,nc}});
                    }
                    }
            }
        }
        return 0;
    }
};