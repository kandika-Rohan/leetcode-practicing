class Solution {
public:
 int f(int i, int j, vector<int>& cuts,vector<vector<int>>&dp) {
    if (i > j) {
        return 0;
    }
    if(dp[i][j] != -1){
        return dp[i][j];
    }
    int mini = 1e9;
    for (int k = i; k <= j; ++k) {
        int cost = cuts[j + 1] - cuts[i - 1] + f(i, k - 1, cuts,dp) + f(k + 1, j, cuts,dp);
        mini = min(cost, mini);
    }
    return dp[i][j]=mini;
}

int minCost(int n, vector<int>& cuts) {
    cuts.insert(cuts.begin(), 0);
    cuts.push_back(n);
    sort(cuts.begin(), cuts.end());
    int m = cuts.size();
    vector<vector<int>> dp(m+2, vector<int>(m+2, 0));

    for (int i =m-2; i >= 1; --i) {
        for (int j = i; j <= m-2; ++j) {
            int mini = 1e9;
            for (int k = i; k <= j; ++k) {
                int cost = cuts[j + 1] - cuts[i - 1] + dp[i][k - 1] + dp[k + 1][j];
                mini = min(mini, cost);
            }
            dp[i][j] = mini;
        }
    }

    return dp[1][m-2];
}
};