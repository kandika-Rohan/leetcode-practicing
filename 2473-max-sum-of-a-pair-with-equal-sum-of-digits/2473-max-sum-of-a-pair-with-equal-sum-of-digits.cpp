#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumSum(vector<int>& nums) {
        unordered_map<int, int> map;
        int maxi = -1;

        for(int i = 0; i < nums.size(); i++) {

            int num = nums[i];

            int sum = 0;

            while (num > 0) {
                
                sum += num % 10;
                num /= 10;
            }

           
            if (map.find(sum) != map.end()) {
                maxi = max(maxi, map[sum] + nums[i]);
            }
            
    
            map[sum] = max(map[sum], nums[i]);
        }

        return maxi;
    }
};
