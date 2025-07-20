class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        long long ans = 0;

        for (int i = 0; i < n; i++) {
            int l = lower - nums[i];
            int r = upper - nums[i];

            // Only look in the range (i+1 to end) to ensure i < j
            int idx1 = lower_bound(nums.begin() + i + 1, nums.end(), l) - nums.begin();
            int idx2 = upper_bound(nums.begin() + i + 1, nums.end(), r) - nums.begin();

            ans += (idx2 - idx1); // valid j such that i < j
        }

        return ans;
    }
};
