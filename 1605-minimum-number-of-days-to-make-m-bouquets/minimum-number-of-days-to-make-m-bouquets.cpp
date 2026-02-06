class Solution {
public:
    int func(vector<int> v,int n,int m,int k,int mid){
        int maxi=0,bloom=0;
        for(int i=0;i<n;i++){
            if(v[i]<=mid){
                bloom++;
            }
            else{
                maxi+=bloom/k;
                bloom=0;
            }
        }
        maxi+=bloom/k;
        if(mid==3)cout<<maxi<<" ans att 3"<<endl;
        return maxi;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        long long one = 1LL * m * k;
        if(one>bloomDay.size())return -1;
        int right=*max_element(bloomDay.begin(),bloomDay.end());
        int left=1,ans=0;
        while(left<=right){
            int mid = right-(right-left)/2;
            cout<< mid <<" ";
            if(func(bloomDay,bloomDay.size(),m,k,mid) >= m){
                ans=mid;
                right=mid-1;
                cout<<"yes ";
            }
            else{
                left=mid+1;
            }
        }
        return ans;
    }
};