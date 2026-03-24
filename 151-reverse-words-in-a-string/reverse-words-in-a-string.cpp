class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(),s.end());
        string ans = "";
        stack<char> st;
        bool flag=false,check=true;
        for(int i=0;i<s.size();i++){
            while(s[i]==' ' && !st.empty()){
                flag=true;
                ans+=st.top();
                st.pop();
            }
            if(flag){
                ans+=' ';
                flag = false;
            }
            if(s[i]!=' ')st.push(s[i]);
        }
        while(!st.empty()){
            check=false;
            ans+=st.top();
            st.pop();
        }
        // cout<<ans;
        // ans = ans(ans.begin(),ans.end()-1);
        if(check)ans.pop_back();
        return ans;
    }
};