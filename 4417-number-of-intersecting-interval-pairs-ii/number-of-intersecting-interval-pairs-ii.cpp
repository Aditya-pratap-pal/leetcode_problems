#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

// using namespace std;
using namespace __gnu_pbds;

typedef tree<
    pair<int,int>,
    null_type,
    less<pair<int,int>>,
    rb_tree_tag,
    tree_order_statistics_node_update
> ordered_set;


class Solution {
public:
    long long countIntersectingIntervals(vector<vector<int>>& intervals) {
         int n = intervals.size();

        // Sort by left endpoint
        sort(intervals.begin(), intervals.end());

        ordered_set st;

        long long ans = 0;

        for (int i = 0; i < n; i++) {

            int l = intervals[i][0];
            int r = intervals[i][1];

            // Number of previous intervals having end < l
            int nonIntersecting =
                st.order_of_key({l, -1});

            // Total previous intervals = i
            // Therefore remaining intervals intersect
            ans += i - nonIntersecting;

            // Insert current right endpoint
            st.insert({r, i});
        }

        return ans;
    }
};