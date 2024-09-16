class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        
        vector<int> times;

        for(auto it: timePoints){
            int hr = stoi(it.substr(0, 2));
            int mint = stoi(it.substr(3, 2)); // corrected minute extraction

            if(hr == 0){
                hr = 24;
            }
            hr = hr * 60;
            times.push_back(hr + mint);
        }
        
        sort(times.begin(), times.end());

        int mini = INT_MAX;
        for(int i = 0; i < times.size() - 1; i++){
            mini = min(mini, times[i+1] - times[i]);
        }
        
        // Check circular time difference (between first and last elements)
        mini = min(mini, 1440 + times[0] - times.back());
        
        return mini;
    }
};
