class Solution {
public:
    void func(vector<int> &nums,vector<int> &ans,vector<vector<int>> &finalAns,int i){
        if(i==nums.size()){
            finalAns.push_back(ans);
            return ;
        }
        //take
        ans.push_back(nums[i]);
        func(nums,ans,finalAns,i+1);
        //not-take
        ans.pop_back();
        func(nums,ans,finalAns,i+1);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> ans;
        vector<vector<int>> finalAns;
        func(nums,ans,finalAns,0);
        return finalAns;
    }
};