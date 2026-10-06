class Solution {
public:
    int minAddToMakeValid(string s) {
        int n=s.size();
        stack<int> st;
        int br1=0,br2=0,cnt=0;
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                st.push(1);
                br1++;
            }
            else{
                if(st.empty()){
                    cnt++;
                    continue;
                }
                st.pop();
                br2++;
            }
        }
        return cnt+br1-br2;
    }
};