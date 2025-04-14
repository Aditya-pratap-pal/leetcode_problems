class Solution {
public:
    bool func(vector<int>& v,int n,int target,int a,int b,int c,int d,int i){
        if(a==target && b==target && c==target && d==target)return true;
        if(a>target || b>target || c>target || d>target)return false;
        bool ans=func(v,n,target,a+v[i],b,c,d,i+1);
        if(ans)return true;
        ans=ans||func(v,n,target,a,b+v[i],c,d,i+1);
        if(ans)return true;
        ans=ans||func(v,n,target,a,b,c+v[i],d,i+1);
        if(ans)return true;
        ans=ans||func(v,n,target,a,b,c,d+v[i],i+1);
        return ans;
    }
    bool makesquare(vector<int>& v) {
        int n=v.size();
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=v[i];
        }
        sort(v.rbegin(),v.rend());
        if(sum%4==0){
            return func(v,n,sum/4,0,0,0,0,0);
        }
        else return false;
    }
};