class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        vector<int>ans;
        for(auto it:grid){
            for(auto q:it){
                ans.push_back(q);
            }
       }
       sort(ans.begin(),ans.end());
       int k=1;
       for(int i=0;i<ans.size();i++){
        if(ans[i]==k){
            k++;
        }
       }
       int res=-1;
       for(int i=1;i<ans.size();i++){
        if(ans[i]==ans[i-1]){
            res=ans[i];
            break;
        }
       }
       return {res,k};
    }
};