class Solution {
public:
    class compare{
        public:
        bool operator()(pair<int,string>a,pair<int,string>b){
            if(a.first==b.first){
                return a.second > b.second;
            }
            return a.first > b.first;
        }
    };
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        vector<pair<int,string>>ans;
        for(int i=0;i<names.size();i++){
            ans.push_back({heights[i],names[i]});
        }

        sort(ans.begin(),ans.end(),compare());

        vector<string>res;
        for(auto it:ans){
            res.push_back(it.second);
        }
        return res;
    }
};