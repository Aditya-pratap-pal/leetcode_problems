class Solution {
public:
    int sum(int num){
        if(num<10)return num;
        return num%10+sum(num/10);
    }
    int addDigits(int num) {
        if(num<10)return num;
        int ans = sum(num);
        return addDigits(ans);
    }
};