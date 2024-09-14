class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int l=0;
        int r=0;
        int m=s.size();
        int n=g.size();
        while(l<m && r<n){
            if(g[r]<=s[l]){
                // l++;
                r++;
            }
            l++;
        }
        return r;
    }
};