class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char,int> mp;
        int l=0,r=0,len=0;
        for(;r<s.size();r++){
            while(mp.find(s[r])!=mp.end()){
                char ch = s[l];
                mp[ch]--;
                if(mp[ch]==0){
                    mp.erase(ch);
                }
                l++;
            }
            mp[s[r]]++;
            len=max(len,r-l+1);
        }
        return len;
    }
};