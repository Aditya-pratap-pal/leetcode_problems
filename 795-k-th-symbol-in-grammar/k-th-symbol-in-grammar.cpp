class Solution {
public:
    int kthGrammar(int n, int k) {
        if(n == 1) return 0;
         
         
         int totalCols = pow(2 , n-1);
         if(k <= totalCols/2){
             int ans =  kthGrammar( n-1 , k);
             return ans;
         }
         else{
            int temp = totalCols/2;
            k = k-temp;
            int ans =  kthGrammar( n-1 , k);
            return !ans;

         }
        
       
    }
};