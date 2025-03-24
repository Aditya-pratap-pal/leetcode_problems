class Solution {
public:
    vector<vector<int>> dp;
    bool solve(vector<int> v,int n,int i,int target){
        if(target==0)return true;
        if(i>=n)return false;
        if(dp[i][target]!=-1)return dp[i][target];
        if(v[i]>target){
            return dp[i][target] = solve(v,n,i+1,target);
        }
        return dp[i][target] = solve(v,n,i+1,target-v[i])||solve(v,n,i+1,target);
    }
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        dp.resize(n,vector<int>((sum/2)+1,-1));
        if(sum%2==0)return solve(nums,n,0,sum/2);
        else return false;
    }
};