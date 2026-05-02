#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
// #define long long long
typedef tree<pair<long long int ,long long int>, null_type, less<pair<long long int,long long int>>,
             rb_tree_tag, tree_order_statistics_node_update> ordered_set;


class Solution {
public:
    int reversePairs(vector<int>& nums) {
        ordered_set s;
        long long n=nums.size();
        long long  ans=0;
        for(long long  i=0;i<n;i++){
            ans+= s.size()-s.order_of_key({2LL * nums[i],i});
            s.insert({nums[i],i});
        }
        return ans;
    }
};