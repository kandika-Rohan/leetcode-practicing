class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int min_val = arrays[0][0];
        int max_val = arrays[0].back();
        int max_distance = 0;

        for (int i = 1; i < arrays.size(); i++) {
            // Calculate the distance considering the 
            // urrent array's first and last elements
            max_distance = max(max_distance, max(abs(arrays[i].back() - min_val), abs(max_val - arrays[i][0])));

            // Update global minimum and maximum values
            min_val = min(min_val, arrays[i][0]);
            max_val = max(max_val, arrays[i].back());
        }

        return max_distance;
    }
};