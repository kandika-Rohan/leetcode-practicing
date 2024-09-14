class Solution {
public:
    void solve(int i,string digits,string map[],vector<string>&ans,string temp){
        if( i >= digits.size() ){
            if(!temp.empty()){
                ans.push_back(temp);
            }
            return;
        }

        int val=digits[i]-'0';
        string s=map[val];

        for(int j=0;j<s.size();j++){
            temp.push_back(s[j]);
            solve(i+1,digits,map,ans,temp);
            temp.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        
        string map[]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

        vector<string>ans;
        solve(0,digits,map,ans,"");
        return ans;
    }
};