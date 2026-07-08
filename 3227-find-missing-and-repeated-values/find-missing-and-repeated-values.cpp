class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n=grid.size();
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++)mp[grid[i][j]]++;
        }
        int missing=-1,duplicate=-1;
        for(int i=1;i<=n*n;i++){
            if(mp[i]==0)missing=i;
            // if(mp.count(i)==mp.end())missing=i;
            if(mp[i]==2)duplicate=i;
        }
        return {duplicate,missing};
    }
};