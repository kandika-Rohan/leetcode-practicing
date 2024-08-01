class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        intervals.push_back(newInterval);


        sort(intervals.begin(),intervals.end());
        vector<int>curr_interval=intervals[0];
        vector<vector<int>> ans;
        for(int i=1;i<intervals.size();i++){
            if(curr_interval[1]>=intervals[i][0]){
                curr_interval[1]=max(curr_interval[1],intervals[i][1]);
            }
            else{
                ans.push_back(curr_interval);
                curr_interval=intervals[i];
            }
        }
        ans.push_back(curr_interval);
        return ans;
    }
};