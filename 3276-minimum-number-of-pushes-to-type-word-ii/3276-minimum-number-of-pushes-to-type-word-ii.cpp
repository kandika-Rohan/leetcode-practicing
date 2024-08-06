class Solution {
public:
    int minimumPushes(string word) {
        vector<int>cnt(26,0);
        for(auto it:word){
            cnt[it-'a']++;
        }
        int ans=0;
        sort(cnt.rbegin(),cnt.rend());
        for(int i=0;i<26;i++){
            cout <<cnt[i]<<" ";
            ans=ans+(i/8+1)*cnt[i];
        }
        return ans;
    }
};