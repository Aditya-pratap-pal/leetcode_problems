class Solution {
public:
void func(vector<string>& input,vector<string>& ans,string curr,int inputIdx){
    if(inputIdx>=input.size()){
        ans.push_back(curr);
        return;
    }
    for(int i=0;i<input[inputIdx].size();i++){
        // if(i+j>=input[j].size())return;
        char ch = input[inputIdx][i];
        func(input,ans,curr+ch,inputIdx+1);
    }
}
    vector<string> letterCombinations(string digits) {
        vector<string> input,ans;
        map<char,string> mp;
        mp['2']="abc";
        mp['3']="def";
        mp['4']="ghi";
        mp['5']="jkl";
        mp['6']="mno";
        mp['7']="pqrs";
        mp['8']="tuv";
        mp['9']="wxyz";
        for(auto it:digits){
            input.push_back(mp[it]);
        }
        // for(int i=2;i<=9;i++){
        //     input.push_back(mp[i]);
        // }
        func(input,ans,"",0);
        return ans;
    }
};