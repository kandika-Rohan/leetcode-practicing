#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    void merge(int low, int mid, int high, vector<int>& nums, int &count) {
        int start = low;
        int end = mid + 1;

        // Count reverse pairs
        int j = mid + 1;
        for (int i = low; i <= mid; ++i) {
            while (j <= high && (long long)nums[i] > 2 * (long long)nums[j]) {
                ++j;
            }
            count += (j - (mid + 1));
        }

        // Merge the two halves
        vector<int> temp;
        int left = low, right = mid + 1;
        while (left <= mid && right <= high) {
            if (nums[left] <= nums[right]) {
                temp.push_back(nums[left++]);
            } else {
                temp.push_back(nums[right++]);
            }
        }
        while (left <= mid) {
            temp.push_back(nums[left++]);
        }
        while (right <= high) {
            temp.push_back(nums[right++]);
        }
        for (int i = 0; i < temp.size(); ++i) {
            nums[low + i] = temp[i];
        }
    }

    void mergesort(int low, int high, vector<int>& nums, int &count) {
        if (low >= high) {
            return;
        }
        int mid = low + (high - low) / 2;
        mergesort(low, mid, nums, count);
        mergesort(mid + 1, high, nums, count);
        merge(low, mid, high, nums, count);
    }

    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        mergesort(0, n - 1, nums, count);
        return count;
    }
};
