class Solution {
public:
    int pivotIndex(vector<int> v,int n){
        int l=0,r=n-1;
        while(l<=r){
            int mid = l+(r-l)/2;
            if(l==r)return l;
            if((mid+1)<n && v[mid]>v[mid+1]){
                return mid;
            }
            if((mid-1)>=0 && v[mid]<v[mid-1]){
                return mid-1;
            }
            if(v[mid]>v[0]){
                l=mid+1;
            }else{
                r=mid-1;
            }
        }
        return -1;
    }
    int findMin(vector<int>& nums) {
        int pivot = pivotIndex(nums,nums.size());
        if(pivot+1<nums.size())nums[0]=min(nums[0],nums[pivot+1]);
        return nums[0];
    }
};