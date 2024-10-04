#include <vector>
#include <string>

class Solution {
public:
    std::vector<std::string> summaryRanges(std::vector<int>& nums) {
        std::vector<std::string> res;
        int n = nums.size();
        if (n == 0) return res;
        
        int i = 0;
        while (i < n) {
            int start = i;
            while (i + 1 < n && nums[i + 1] == nums[i] + 1) {
                i++;
            }
            if (start == i) {
                res.push_back(std::to_string(nums[start]));
            } else {
                res.push_back(std::to_string(nums[start]) + "->" + std::to_string(nums[i]));
            }
            i++;
        }

        return res;
    }
};
