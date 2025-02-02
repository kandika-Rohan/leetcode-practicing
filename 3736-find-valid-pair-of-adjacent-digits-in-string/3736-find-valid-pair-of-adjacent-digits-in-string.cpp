class Solution {
public:
    string findValidPair(string s) {
        
        unordered_map<int,int>map;

        for(auto it:s){
            map[it - '0']++;
        }

        for(auto it:map){
            cout<<it.first<<" "<<it.second<<endl;
        }

        string ans="";

        for(int i=1;i<s.size();i++){

            int val1=s[i]-'0';
            int val2=s[i-1]-'0';

            if(val1 != val2 && map[val1] == val1 && map[val2] == val2){
                ans+=s[i-1];
                ans+=s[i];
                return ans;
            } 
        }

        return ans;
    }
};