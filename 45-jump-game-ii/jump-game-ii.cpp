class Solution {
public:
    // int solve(vector<int> &v,int n){
    //     if(i>=n)return 0;
    //     int jump=0;
    //     for(int j=i+v[i];j>0;j--){

    //     }
    // }
    int jump(vector<int>& nums) {
        int far=0,near=0,jump=0;
        while(far<nums.size()-1){
            int fastest=0;
            for(int i=near;i<=far;i++){
                fastest=max(fastest,i+nums[i]);
            }
            near=far+1;
            far=fastest;
            jump++;
        }
        return jump;
    }
};