class Solution {
public:
    bool ispalindrome(int i,int j,string s){
        if(i == j)return true;
        while(i<=j){
            if(s[i]  != s[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    void solve(int i,string s,vector<string>&m,vector<vector<string>>&ans){
        if(i>=s.size()){
            ans.push_back(m);
            return ;
        }

        for(int j=i;j<s.size();j++){

            if(ispalindrome(i,j,s)){
                
                m.push_back(s.substr(i,j-i+1));
                solve(j+1,s,m,ans);
                m.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        vector<string>ds;
        solve(0,s,ds,ans);
        return ans;
    }
};