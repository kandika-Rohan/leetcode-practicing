class Solution {
public:
   static bool comp(string a,string b){
    return a<b;
   }
    vector<int> lexicalOrder(int n) {
        vector<string>ans;
        for(int i=1;i<=n;i++){
            ans.push_back(to_string(i));
        }
        sort(ans.begin(),ans.end(),comp);
        vector<int>rs;
        for(int i=0;i<n;i++){
            rs.push_back(stoi(ans[i]));
        }
        return rs;
    }
};