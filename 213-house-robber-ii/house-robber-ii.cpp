class Solution {
public:
vector<int> dp;
    int money(vector<int> &v,int n,int i){
        if(i>=n)return dp[i] = 0;
        // if(flag && i==n-1 && n!=1)return dp[i] = 0;
        if(dp[i]!=-1) return dp[i];
        int one = v[i]+money(v,n,i+2);
        int two = money(v,n,i+1);
        return dp[i] = max(one,two);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];

        dp.assign(n+2,-1);
        int one = money(nums,n-1,0);

        dp.assign(n+2,-1);
        int two = money(nums,n,1);

        return max(one,two);
    }
};