class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int cnt=0;
        set<char>st(allowed.begin(),allowed.end());
        for(auto it:words){
            bool flag=false;
            for(auto c:it){
                if(st.find(c) == st.end()){
                    flag=true;
                    break;
                }
            }
            if(flag==false){
                cnt++;
            }
        }
        return cnt;
    }
};