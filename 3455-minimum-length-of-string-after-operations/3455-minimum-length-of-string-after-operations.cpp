class Solution {
public:
    int minimumLength(string s) {
        unordered_map<char,int>map;

        for(int i=0;i<s.size();i++){
            map[s[i]]++;
        }
        for(char it:s){
            if(map[it] >= 3){
                map[it]-=2;
                if(map[it]==0){
                    map.erase(it);
                }
            }
        }
        int count=0;
        for(auto it:map){
            count+=it.second;
        }
        return count;
    }
};