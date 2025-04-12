class Solution {
public:
    bool bs(vector<int>& v, int left, int right, int mid, int k) {
        int par = 1, sum = 0;
        for (int i = 0; i < v.size(); i++) {
            if (v[i] > mid)
                return true;
            sum += v[i];
            if (sum> mid) {
                par++;
                sum = v[i];
            }
            if (par > k)
                return true;
        }

        return false;
    }
    int splitArray(vector<int>& nums, int k) {
        int left = 0, right = 1e9 + 1, ans;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (bs(nums, left, right, mid, k)) {
                left = mid + 1;
            } else {
                ans = mid;
                right = mid - 1;
            }
        }
        return ans;
    }
};