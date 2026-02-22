class Solution {
public:
    int binaryGap(int n) {
        int distance=0;
        vector<int> one;
        int i=0;
        while(n>0){
            cout<<i<<" ";
            if(n&1)one.push_back(i);
            n>>=1;
            i++;
        }
        for(int i=0;i<one.size()-1;i++){
            distance = max(distance,abs(one[i]-one[i+1]));
        }
        return distance;
    }
};