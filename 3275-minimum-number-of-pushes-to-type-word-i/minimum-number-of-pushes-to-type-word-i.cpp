class Solution {
public:
    int minimumPushes(string word) {
        vector<int> fre(26,0);
        for(int i=0;i<word.size();i++){
            fre[word[i]-'a']++;
        }
        int cnt=0;
        sort(fre.rbegin(),fre.rend());
        for(int i=0;i<26;i++){
            if(i<8){
                cnt+=fre[i];
            }
            else if(i<16){
                cnt+=fre[i]*2;
            }
            else if(i<24){
                cnt+=fre[i]*3;
            }
            else{
                cnt+=fre[i]*4;
            }
        }
        return cnt;
    }
};