#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> dp;
    int offset = 10001; // Shifting negative values to valid indices

    int solve(vector<int>& v, int n, int i, int prev) {
        if (i >= n) return 0;

        if (dp[i][prev + offset] != -1) return dp[i][prev + offset];

        int take = 0;
        if (prev == -10001 || v[i] > prev) { // -10001 is the initial 'prev'
            take = 1 + solve(v, n, i + 1, v[i]);
        }
        int not_take = solve(v, n, i + 1, prev);

        return dp[i][prev + offset] = max(take, not_take);
    }

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        dp.resize(n, vector<int>(2 * offset + 5, -1)); // To handle full range [-1e4-1, 1e4]
        return solve(nums, n, 0, -10001); // Start with an impossible minimum value
    }
};

// int main() {
//     Solution sol;
//     vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};
//     cout << sol.lengthOfLIS(nums) << endl;  // Output: 4
//     return 0;
// }
