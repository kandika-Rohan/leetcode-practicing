class Solution {
public:
    string reverseWords(string s) {
        string temp="";
        vector<string>ans;

        for(int i=0;i<s.size();i++){
            
            if(s[i] == ' '){
                if(!temp.empty()){
                    ans.push_back(temp);
                    temp="";
                }
            }
            else{
                temp+=s[i];
            }
        }
        if(!temp.empty())ans.push_back(temp);

        reverse(begin(ans),end(ans));

        string res="";
        for(auto it:ans){
            if(res.empty()){
                res+=it;
            }
            else{
                res=res+" "+it;
            }
        }
        return res;
    }
};