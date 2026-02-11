class Solution {
public:
void func(int n,vector<string>& ans,int open,int close,string currS){
    if(open>=n && close>=n){
        ans.push_back(currS);
        return;
    }
    if(open>=n){
        func(n,ans,open,close+1,currS+')');
        // return;
    }
    else if(close<open){
        func(n,ans,open+1,close,currS+'(');
        func(n,ans,open,close+1,currS+')');
    }
    else if(close==open){
        func(n,ans,open+1,close,currS+'(');
    }
}
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        func(n,ans,0,0,"");
        return ans;
    }

};