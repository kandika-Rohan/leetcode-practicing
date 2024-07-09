class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        long long sum = 0;
        int finishes = customers[0][0] + customers[0][1];
        sum += (finishes - customers[0][0]);
        
        for (int i = 1; i < customers.size(); i++) {
            if (finishes < customers[i][0]) {
                finishes = customers[i][0];
            }
            finishes += customers[i][1];
            sum += (finishes - customers[i][0]);
        }

        return static_cast<double>(sum) / customers.size();
    }
};
