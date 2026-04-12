class Solution {
public:
vector<vector<int>> dp;
    int common(string &s1,string &s2,int n,int m,int i,int j){
        if(i>=n || j>=m)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        int first,second,third;
        if(s1[i]==s2[j]){
            third = common(s1,s2,n,m,i+1,j+1);
            return dp[i][j] = 1+third;
        }
        return dp[i][j] = max(common(s1,s2,n,m,i+1,j),common(s1,s2,n,m,i,j+1));
    }
    int longestCommonSubsequence(string text1, string text2) {
        dp.resize(text1.size(),vector<int>(text2.size(),-1));
        return common(text1,text2,text1.size(),text2.size(),0,0);
    }
};