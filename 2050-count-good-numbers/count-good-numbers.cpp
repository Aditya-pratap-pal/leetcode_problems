class Solution {
public:
long long mod = 1e9+7;
long long power(long long a, long long n) {
    long long result = 1;

    while (n > 0) {
        if (n & 1)          // if n is odd
            result = ((result%mod)*(a%mod))%mod;

        a = ((a%mod)*(a%mod))%mod;             // square the base
        n >>= 1;            // n = n / 2
    }
    return result%mod;
}
    int countGoodNumbers(long long n) {
        long long ans=1;
        long long mod=1e9+7;
        long long ans1=1,ans2=1;
        if(n%2==0){
            long long temp = n/2;
            ans1=power(5,temp);
            ans2=power(4,temp);
        }
        else{
            long long temp=n/2;
            ans1=power(5,temp+1);
            ans2=power(4,temp);
        }
        ans= ((ans1%mod)*(ans2%mod))%mod;
        return  ans;
    }
};