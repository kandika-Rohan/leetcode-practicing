class Solution {
public:
    unordered_map<int ,string>map;
    string countAndSay(int n) {

        if(map.find(n) != map.end()){

            return map[n];
        }
        if(n ==1){
            return "1";
        }
        if(n ==2){
            return "11";
        }
        string prev=countAndSay(n-1);
        string res="";
        int i=0;
        while(i<prev.size()){
            int cnt=1;
            while(i+1<prev.size() && prev[i] == prev[i+1]){
                cnt++;
                i++;
            }

            res+=to_string(cnt)+prev[i];
            i++;
        }

        map[n]=res;
        return res;
    }
};