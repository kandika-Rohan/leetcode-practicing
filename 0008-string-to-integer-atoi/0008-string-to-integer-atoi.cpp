class Solution {
public:
    int myAtoi(string s) {
        string res="";
        for(int i=0;i<s.length();i++){
            if(!s[i+1]>='a' || !s[i+1]<='z'){
                res+=s[i];
            }
        }
        stringstream sso;
        sso<<res;
        int total=0;
        sso>>total;
        return total;
    }
};