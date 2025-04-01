class Solution {
public:
    string removeOuterParentheses(string s) {
        int n=s.length();
        int open=0,close=0;
        string ans="";
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                open++;
            }
            else if(s[i]==')'){
                close++;
            }
            if(open==close){
                open=0;
                close=0;
            }
            if(open>1){
                ans+=s[i];
            }
        }
        return ans;
    }
};