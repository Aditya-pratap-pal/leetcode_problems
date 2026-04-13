class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int n= nums.size();
        int maxi = *max_element(nums.begin(),nums.end());
        int maxCount=0,l=0;
        long long ans=0;
        for(int r=0;r<n;r++){
            if(nums[r]==maxi)maxCount++;
            while(maxCount>=k){
                ans+=(n-r);
                if(nums[l]==maxi)maxCount--;
                l++;
            }
        }
        return ans;
    }
};