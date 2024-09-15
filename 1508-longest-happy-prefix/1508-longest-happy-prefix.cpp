class Solution {
public:
    vector<int> lps(string p){
        int n=p.size();
        vector<int>ans(n,0);
        int i=1;
        int len=0;
        while(i<n){
            if(p[i] == p[len]){
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
        return ans;
    }
    string longestPrefix(string s) {
        
        vector<int>lp=lps(s);
        for(auto it:lp){
            cout<<it<<" ";
        }
        
        return s.substr(0,lp.back());
    }
};