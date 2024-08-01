class Solution {
public:
   vector<vector<int>> merge(vector<vector<int>>& intervals) {
    // If there are no intervals, return an empty list
    if (intervals.empty()) {
        return {};
    }

   
    sort(intervals.begin(), intervals.end());


    vector<vector<int>> ans;
    vector<int> current_interval = intervals[0];

    for (int i = 1; i < intervals.size(); i++) {
   
        if (current_interval[1] >= intervals[i][0]) {
            current_interval[1] = max(current_interval[1], intervals[i][1]);
        } else {
       
            ans.push_back(current_interval);
            current_interval = intervals[i];
        }
    }



    ans.push_back(current_interval);

    return ans;
}
};