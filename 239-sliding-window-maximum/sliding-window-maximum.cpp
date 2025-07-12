class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n=nums.size();
        map<int,int> mp;
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(i<k-1){
                mp[nums[i]]++;
                continue;
            }
            if(i>=k){
                mp[nums[i-k]]--;
                if(mp[nums[i-k]]==0){
                    mp.erase(nums[i-k]);
                }
            }
            mp[nums[i]]++;
            auto lastPair = prev(mp.end());
            ans.push_back(lastPair->first);
        }
        return ans;
    }
};