class Solution {
public:
    int numberOfSubstrings(string s) {
        vector<int> v(3,-1);
        int ans=0;
        int mini;
        for(int i=0;i<s.length();i++){
           v[s[i]-97]=i;
           if(v[0]!=-1 &&  v[1]!=-1 && v[2]!=-1){
              mini=min(v[0],min(v[1],v[2]));
             ans+=mini+1;
              
           }
        }

        return ans;
    }
};