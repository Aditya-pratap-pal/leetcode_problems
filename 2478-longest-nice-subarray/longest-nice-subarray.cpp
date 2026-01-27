class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int l=0,bit=0,ans=1;
        for(int r=0;r<nums.size();r++){
            while((bit&nums[r])!=0){
                bit = bit ^ nums[l];
                l++;
            }
            bit = bit | nums[r];
            ans=max(ans,r-l+1);
        }
        return ans;
    }
};