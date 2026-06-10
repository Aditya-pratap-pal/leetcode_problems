class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int i=0,j=0,n=nums.size();
        int cnt=0,ans=0;
        unordered_map<int,int> mp;
        mp[0]=1;
        while(j<n){
            if(nums[j]%2!=0)cnt++;
            if(mp.find(cnt-k)!=mp.end())ans+=mp[cnt-k];
            mp[cnt]++;
            j++;
            // while(cnt>=k){
            //     if(mp.find())
            //     if(nums[j]%2!=0)cnt--;
            //     j++;
            // }

        }
        return ans;
    }
};