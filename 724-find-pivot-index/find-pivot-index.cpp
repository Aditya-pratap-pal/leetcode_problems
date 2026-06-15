class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix(n);
        prefix[0]=nums[0];
        for(int i=1;i<n;i++){
            prefix[i]=nums[i]+prefix[i-1];
        }
        for(int i=0;i<n;i++){
            int leftsum=0,rightsum=0;
            if(i>0) leftsum = prefix[i-1];
            rightsum = prefix[n-1]-prefix[i];
            if(leftsum==rightsum)return i;
        }
        return -1;
    }
};