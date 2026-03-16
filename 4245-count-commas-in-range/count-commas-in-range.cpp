class Solution {
public:
    int countCommas(int n) {
        long long threshold=1e3,comma=0;
        while(n>=threshold){
            comma+=(n-threshold+1);
            if(threshold>=LLONG_MAX/1000)break;
            threshold*=1000;
        }
        return comma;
    }
};