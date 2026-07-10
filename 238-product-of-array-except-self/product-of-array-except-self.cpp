class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n,1);
        vector<int> prefix(n),suffix(n);
        prefix[0]=nums[0];
        suffix[n-1]=nums[n-1];
        for(int i=1;i<nums.size();i++){
            prefix[i]=prefix[i-1]*nums[i];
        }
        for(int i=n-2;i>=0;i--){
            suffix[i]=suffix[i+1]*nums[i];
        }
        for(int i=0;i<n;i++){
            if((i-1)>=0)ans[i]*=prefix[i-1];
            if((i+1)<n)ans[i]*=suffix[i+1];
        }
        return ans;
    }
};