class Solution {
public:
    int alternating(vector<int> v,int n){
        long long sum1 = 0,sum2=0;
        for(int i=0;i<n;i++){
            if(i&1)sum1+=v[i];
            else sum2+=v[i];
        }
        return sum2-sum1;
    }
    void subSequence(vector<int>& v,int n,vector<int> &sub,int i,long long &ans){
        if(i>n)return;
        if(i==n){
            long long sum = alternating (sub,sub.size());
            ans=max(ans,sum);
            return;
        }
        sub.push_back(v[i]);
        subSequence(v,n,sub,i+1,ans);
        sub.pop_back();
        subSequence(v,n,sub,i+1,ans);
    }
    long long maxAlternatingSum(vector<int>& nums) {
        // long long ans = 0;
        // vector<int> sub;
        // subSequence(nums,nums.size(),sub,0,ans);
        // return ans;

        //Tabulation...........
        int n=nums.size();
        vector<vector<long long>> dp(n+1, vector<long long>(2, 0));
        for(int i=1;i<=n;i++){
            dp[i][0] = max(dp[i-1][0],dp[i-1][1]-nums[i-1]);
            dp[i][1] = max(dp[i-1][1],dp[i-1][0]+nums[i-1]);
        }
        return max(dp[n][0],dp[n][1]);
    }
};