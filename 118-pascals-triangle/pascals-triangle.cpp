class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans(numRows);
        if(numRows==1)return {{1}};
        if(numRows==2)return {{1},{1,1}};
        ans[0].push_back(1);
        ans[1].push_back(1);
        ans[1].push_back(1);
        numRows-=2;
        int i=2;
        while(numRows--){
            ans[i].push_back(1);
            for(int j=1;j<=ans[i-1].size()-1;j++){
                ans[i].push_back(ans[i-1][j-1]+ans[i-1][j]);
            }
            ans[i].push_back(1);
            i++;
        }
        return ans;
    }
};