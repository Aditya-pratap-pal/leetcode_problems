class Solution {
public:
    bool isPowerOfFour(int n) {
        // Base Case
        if(n <=0) return false;
        if(n == 1) return true;

        // Small Calculation
        if(n%4 != 0) return false;

        return isPowerOfFour(n/4);
    }
};