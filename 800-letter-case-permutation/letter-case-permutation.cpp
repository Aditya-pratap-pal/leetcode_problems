class Solution {
public:
    void permutationWithCaseChange(string s,vector<string> &ans,string currS,int i) {
        if(i>=s.length()){
            ans.push_back(currS);
            return;
        }
        if(isdigit((unsigned char)s[i])){
            permutationWithCaseChange(s,ans,currS+s[i],i+1);
        }
        else{
            permutationWithCaseChange(s,ans,currS+char(toupper(s[i])),i+1);
            permutationWithCaseChange(s,ans,currS+char(tolower(s[i])),i+1);
        }
    }
    vector<string> letterCasePermutation(string s) {
        vector<string> ans;
        permutationWithCaseChange(s,ans,"",0);
        return ans;
    }
};