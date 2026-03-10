class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        vector<int> ans(cost.size());
        if(n==1)return cost[0];
        if(n==2)return min(cost[0],cost[1]);
        ans[0]=cost[0];
        ans[1]=cost[1];
        for(int i=2;i<cost.size();i++){
            ans[i] = min(ans[i-1],ans[i-2])+cost[i];
        }
        return min(ans[n-2],ans[cost.size()-1]);
    }
};