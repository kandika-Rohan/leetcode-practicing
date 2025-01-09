class Solution {
public:
    bool isvalid(string s,string t){
        int i=0;
        int j=0;
        int n=s.size();
        int m=t.size();
        if(s[0] != t[0])return false;
        while(i<n && j<m ){
            if(s[i] != t[j]){
                return false;
            }
            i++;
            j++;
        }
        return j==m;
    }
    int prefixCount(vector<string>& words, string pref) {
        
        int cnt=0;

        for(auto it:words){
            if(isvalid(it,pref)){
                cnt++;
            }
        }
        return cnt;
    }
};