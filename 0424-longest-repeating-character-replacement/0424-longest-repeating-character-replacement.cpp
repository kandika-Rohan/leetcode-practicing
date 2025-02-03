class Solution {
public:
    int characterReplacement(string s, int k) {
        int len=0;
        int maxfreq=0;
        int i=0;
        int hash[26]={0};
        for(int j=0;j<s.size();j++){
            hash[s[j]-'A']++;
            maxfreq=max(maxfreq,hash[s[j]-'A']);
            if((j-i+1)-maxfreq>k){
                hash[s[i]-'A']--;
                maxfreq=0;
                i++;
            }
            if((j-i+1)-maxfreq<=k){
                len=max(len,j-i+1);
            }
        }
        return len;
    }
};