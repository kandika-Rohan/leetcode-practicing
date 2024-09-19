class Solution {
public:
    string longestWord(vector<string>& words) {
        
        sort(words.begin(),words.end());
        unordered_set<string>st(words.begin(),words.end());
        string ans="";
        int maxi=0;
        for(auto it:words){
            string temp="";
            bool valid=true;
            for(int i=0;i<it.size();i++){
                temp+=it[i];
                if(st.find(temp) == st.end()){
                    valid=false;
                    break;
                }
            }

            if(valid){
                if(maxi<temp.size()){
                    maxi=temp.size();
                    ans=temp;
                }
            }
        }
        return ans;
    }
};