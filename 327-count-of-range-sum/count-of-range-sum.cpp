#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<pair<long long,long long>, null_type,
             less<pair<long long,long long>>,
             rb_tree_tag, tree_order_statistics_node_update> ordered_set;

class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        int n = nums.size();
        ordered_set s;

        long long sum = 0;
        long long ans = 0;

        // Important: prefix sum = 0
        s.insert({0, -1});

        for(int i = 0; i < n; i++) {
            sum += nums[i];

            long long left  = sum - upper;
            long long right = sum - lower;

            long long cnt = 
                s.order_of_key({right + 1, -1}) - 
                s.order_of_key({left, -1});

            ans += cnt;

            s.insert({sum, i});
        }

        return ans;
    }
};