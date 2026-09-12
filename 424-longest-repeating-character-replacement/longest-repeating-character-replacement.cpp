class Solution {
public:
    int func(vector<int> &freq){
        int maxi=0;
        for(int i=0;i<=25;i++){
            maxi=max(maxi,freq[i]);
        }
        return maxi;
    }
    int characterReplacement(string s, int k) {
        int i=0,j=0;
        int n=s.size();
        vector<int> freq(26,0);
        int ans=0;
        while(i<n){
            freq[s[i]-'A']++;
            // if(freq[s[i]-'a']==1)cnt++;
            int maxFreqEle=func(freq);
            while(i-j+1-maxFreqEle>k){
                freq[s[j]-'A']--;
                maxFreqEle=func(freq);
                j++;
            }
            if(i-j+1-maxFreqEle<=k)ans=max(ans,i-j+1);
            i++;
        }
        return ans;
    }
};