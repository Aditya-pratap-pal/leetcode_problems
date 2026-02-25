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
        // int n = nums.size();
        // if(n==1) return nums[0];

        // dp.assign(n+2,-1);
        // int one = money(nums,n-1,0);

        // dp.assign(n+2,-1);
        // int two = money(nums,n,1);

        // return max(one,two);
        int n = nums.size();
        vector<int> dp1(n-1,0);
        vector<int> dp2(n,0);
        if(n==1)return nums[0];
        else if(n==2)return max(nums[0],nums[1]);
        else if(n==3)return max({nums[0],nums[1],nums[2]});
        dp1[0]=nums[0];
        dp1[1]=nums[1];
        dp1[2]=nums[2]+nums[0];
        // dp2[0]=nums[0];
        dp2[1]=nums[1];
        dp2[2]=nums[2];
        dp2[3]=nums[1]+nums[3];
        for(int i=3;i<n-1;i++){
            dp1[i]=nums[i]+max(dp1[i-2],dp1[i-3]);
        }
        dp1[n-2]=max(dp1[n-2],dp1[n-3]);
        for(int i=4;i<n;i++){
            dp2[i]=nums[i]+max(dp2[i-2],dp2[i-3]);
        }
        dp2[n-1]=max(dp2[n-1],dp2[n-2]);
        return max(dp1[n-2],dp2[n-1]);
    }
};