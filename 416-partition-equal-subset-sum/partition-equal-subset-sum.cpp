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
        dp.resize(n,vector<int>((sum/2)+1,0));
        // if(sum%2==0)return solve(nums,n,0,sum/2);
        // else return false;
        if(sum&1)return false;
        sum=sum/2;
        for(int i=0;i<n;i++){
            dp[i][0]=1;
        }
        if(nums[0]<=sum)dp[0][nums[0]]=1;
        else return 0;
        for(int i=1;i<n;i++){
            for(int j=1;j<=sum;j++){
                if(nums[i]>j){
                    dp[i][j]=dp[i-1][j];
                }
                else{
                    dp[i][j]= dp[i-1][j-nums[i]] || dp[i-1][j];
                }
            }
        }
        return dp[n-1][sum];
    }
};