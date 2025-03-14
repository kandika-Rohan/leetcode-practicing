class Solution {
public:
    bool ispossible(int i, vector<int>& candies, long long k) {
        long long cnt = 0;
        for (auto it : candies) {
            cnt += (it / i);
            if (cnt >= k) return true; // Early exit to optimize
        }
        return cnt >= k;
    }

    int maximumCandies(vector<int>& candies, long long k) {
        long long total_candies = 0;
        for (int c : candies) total_candies += c;
        
        if (total_candies < k) return 0; // Not enough candies to distribute
        
        int l = 1, r = *max_element(begin(candies), end(candies));
        int ans = 0;

        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (ispossible(mid, candies, k)) {
                ans = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }

        return ans;
    }
};
