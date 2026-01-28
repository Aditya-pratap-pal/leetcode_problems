class Solution {
public:
    bool func(int n,long long  num){
        // if(num<n)cout<<"yes";
        // if(num==n)cout<<"yes. "<<num;
        if(num==n)return true;
        if(num>n)return false;
        return func(n,num*2);

    }
    bool isPowerOfTwo(int n) {
        return func(n,1LL);
    }
};