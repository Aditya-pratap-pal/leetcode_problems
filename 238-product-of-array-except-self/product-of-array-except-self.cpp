class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans;
        int total=1;
        int zero=0;
        for(int i=0;i<n;i++){
            if(nums[i]==0)zero++;
            else total=total*nums[i];
        }
        if(zero>1){
            ans.resize(n,0);
            return ans;
        }
        if(zero==1){
            for(int i=0;i<n;i++){
            if(nums[i]==0){
                ans.push_back(total);
            }
            else{
                ans.push_back(0);
            }
            }
        }
        else{
        for(int i=0;i<n;i++){
            ans.push_back((total/nums[i]));
        }
        }
        return ans;
    }
};