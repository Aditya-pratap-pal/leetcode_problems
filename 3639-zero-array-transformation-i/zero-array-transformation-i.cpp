class Solution {
public:
    bool isZeroArray(vector<int>& v, vector<vector<int>>& q) {
        int n=v.size();
        vector<int> temp(n+1,0);
        for(int i=0;i<q.size();i++){
            temp[q[i][0]]--;
            temp[q[i][1]+1]++;
        }
        for(int i=1;i<=n;i++){
            temp[i]+=temp[i-1];
        }
        for(int i=0;i<n;i++){
            v[i]=v[i]+temp[i];
        }
        bool flag=true;
        for(int i=0;i<n;i++){
            if(v[i]>0){
                flag=false;
                break;
            }
        }
        if(flag)return true;
        return false;

    }
};