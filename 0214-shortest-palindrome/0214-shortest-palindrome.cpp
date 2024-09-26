class Solution {
public:
    int lps(string s){
        int n=s.size();
        vector<int>ans(n,0);

        int i=1;
        int len=0;

        while(i<n){
            if(s[i] == s[len])
            {
                len++;
                ans[i]=len;
                i++;
            }
            else{
                if(len != 0){
                    len=ans[len-1];
                }
                else{
                    ans[i]=0;
                    i++;
                }
            }
        }

        return ans.back();
    }
    string shortestPalindrome(string s) {
        string rev=s;
        reverse(begin(rev),end(rev));

        string str=s+"#"+rev;
        
        int n=lps(str);

        return rev.substr(0, s.size() - n) + s;
    }
};