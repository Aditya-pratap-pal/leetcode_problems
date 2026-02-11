class Solution {
public:
    void func(int n,vector<string> &ans,string currS,int i){
        if(i>=n){
            ans.push_back(currS);
            return;
        }
        func(n,ans,currS+"1",i+1);
        int size=currS.length()-1;
        if(currS.empty() || currS[currS.length()-1]=='1'){
            func(n,ans,currS+"0",i+1);
        }
    }
    vector<string> validStrings(int n) {
        vector<string> ans;
        func(n,ans,"",0);
        // func(n,ans,"0",1);
        return ans;
    }
};