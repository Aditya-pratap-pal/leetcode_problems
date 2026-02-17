class Solution {
public:
void func(vector<vector<char>>& v,int n,int m,int i,int j,bool &flag ,string s,int idx){
    if(i<0||j<0||i>=n||j>=m||v[i][j]=='1'||idx>=s.length())return;
    if(v[i][j] !=s[idx])return;
    if(idx==s.length()-1){
        flag=true;
        return;
    }

    v[i][j]='1';
    func(v,n,m,i+1,j,flag,s,idx+1);
   func(v,n,m,i-1,j,flag,s,idx+1);
    func(v,n,m,i,j+1,flag,s,idx+1);
   func(v,n,m,i,j-1,flag,s,idx+1);
    v[i][j]=s[idx];
}
    bool exist(vector<vector<char>>& board, string word) {
        int n=board.size();
        int m=board[0].size();
        bool flag=false;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                char ch = board[i][j];
                func(board,n,m,i,j,flag , word,0);
            }
        }
        return flag;
    }
};