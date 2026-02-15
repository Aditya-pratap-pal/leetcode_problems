class Solution {
public:
    bool isPalin(string s){
        if(s=="")return true;
        string rs = s;
        reverse(s.begin(),s.end());
        return s==rs;
    }
    void func(string s,int n,int j,vector<string> &curr,vector<vector<string>> &ans){
        if(j>n)return;
        if(j==n){
            ans.push_back(curr);
            return;
        }
        for(int i=1;j+i<=n;i++){
            string str = s.substr(j,i);
            if(isPalin(str)){
                curr.push_back(str);
                func(s,n,j+i,curr,ans);
                curr.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<string> curr;
        vector<vector<string>> ans;
        func(s,s.length(),0,curr,ans);
        return ans;
    }
};