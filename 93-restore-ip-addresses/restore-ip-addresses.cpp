class Solution {
public:
    bool checker(string s){
        if(s=="")return true;
        if(s.length()>=2 && s[0]=='0')return false;
        int n = stoi(s);
        return n>=0 && n<256;
    }
    void func(string s,int n,vector<string> &ans,string curr,int i,int dot){
        if(dot==4 && i==n){
            curr.pop_back();
            ans.push_back(curr);
            return;
        }
        if(i>=n || dot>4)return;
        for(int j=1;j<=3 && i+j<=n;j++){
            string str = s.substr(i,j);
            if(checker(str))func(s,n,ans,curr+str+".",i+j,dot+1);
        }
    }
    vector<string> restoreIpAddresses(string s) {
        vector<string> ans;
        int n=s.length();
        func(s,n,ans,"",0,0);
        return ans;
    }
};