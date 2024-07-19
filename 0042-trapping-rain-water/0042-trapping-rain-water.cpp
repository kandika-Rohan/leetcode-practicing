class Solution {
public:
    vector<int> leftmaxi(vector<int>& arr, int n) {
        vector<int> ans(n, 0); // Change initialization to 0 instead of -1
        int maxLeft = 0; // Initialize maxLeft to 0
        for (int i = 0; i < n; i++) {
            ans[i] = maxLeft; // Assign the maxLeft value to ans
            maxLeft = max(maxLeft, arr[i]); // Update maxLeft to the maximum value seen so far
        }
        return ans;
    }

    vector<int> rightmaxi(vector<int>& arr, int n) {
        vector<int> ans(n, 0); // Change initialization to 0 instead of -1
        int maxRight = 0; // Initialize maxRight to 0
        for (int i = n - 1; i >= 0; i--) {
            ans[i] = maxRight; // Assign the maxRight value to ans
            maxRight = max(maxRight, arr[i]); // Update maxRight to the maximum value seen so far
        }
        return ans;
    }

    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> left = leftmaxi(height, n);
        vector<int> right = rightmaxi(height, n);
        int waterTrapped = 0;
        for (int i = 0; i < n; i++) {
            int minHeight = min(left[i], right[i]); // Find the minimum of left and right heights
            if (minHeight > height[i]) {
                waterTrapped += minHeight - height[i]; // Calculate the trapped water
            }
        }
        return waterTrapped;
    }
};
