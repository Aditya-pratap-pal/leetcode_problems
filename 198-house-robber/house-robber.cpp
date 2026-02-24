class Solution {
public:
    vector<int> dp;
    int money(vector<int>& v,int n,int i){
        if(i>=n)return dp[i] = 0;
        if(dp[i]!=-1) return dp[i];
        int next = v[i]+money(v,n,i+2);
        int nextToNext = money(v,n,i+1);
        return dp[i] = max(next,nextToNext);
    }
    int rob(vector<int>& nums) {
        // dp.resize(nums.size()+2,-1);
        // int idx1 = money(nums,nums.size(),0);
        // int idx2 = money(nums,nums.size(),1);
        // return max(idx1,idx2);

        //Tabulation---------
        int n = nums.size();
        if(n==1)return nums[0];
        else if(n==2)return max(nums[0],nums[1]);
        else if(n==3)return max(nums[0]+nums[2],nums[1]);
        vector<int> dp(n);
        dp[0]=nums[0];
        dp[1]=nums[1];
        dp[2]=nums[2]+nums[0];
        for(int i=3;i<n;i++){
            dp[i]=nums[i]+max(dp[i-2],dp[i-3]);
        }
        return max(dp[n-1],dp[n-2]);
    }
};