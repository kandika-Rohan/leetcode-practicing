#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool ispossible(vector<int>& piles, int h, int mid) {
        int count = 0;
        for (int i = 0; i < piles.size(); i++) {
            count += (piles[i] + mid - 1) / mid; // This is an integer version of ceil(piles[i] / mid)
            if (count > h) {
                return false;
            }
        }
        return count <= h;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1;
        int r = *max_element(piles.begin(), piles.end());
        int ans = -1;

        while (l <= r) {
            int mid = (l + r) / 2;
            if (ispossible(piles, h, mid)) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return ans;
    }
};
