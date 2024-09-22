class Solution {
public:
    bool reportSpam(vector<string>& message, vector<string>& bannedWords) {
        unordered_map<string,int>map;
        for(auto it:bannedWords){
            map[it]++;
        }
        int cnt=0;

        for(auto it:message){

            if(map.find(it) != map.end()){
                cnt++;
            }
            if(cnt>=2)return true;
        }
        return false;
    }
};