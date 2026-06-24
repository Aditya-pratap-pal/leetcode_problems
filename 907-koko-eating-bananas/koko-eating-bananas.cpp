class Solution {
public:
    
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1;
        int right = *max_element(piles.begin(),piles.end());
        int ans = right;
        while(left<=right){
            int mid = left+(right-left)/2;
            long long  time=0;
            for(int i=0;i<piles.size();i++){
                time+= (piles[i]+mid-1)/mid;
            }
            if(time<=h){
                ans = mid;
                right=mid-1;
            }else{
                left = mid+1;
            }
        }
        return ans;
    }
};