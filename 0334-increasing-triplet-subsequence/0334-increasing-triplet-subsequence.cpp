class Solution {
public:
    vector<int> leftmin(vector<int>& nums) {
        vector<int> ans(nums.size(), -1);
        stack<int> st;

        for (int i = 0; i < nums.size(); i++) {
            while (!st.empty() && nums[st.top()] >= nums[i]) {
                st.pop();
            }

            if (!st.empty()) {
                ans[i] = st.top();
            }
            st.push(i);
        }

        return ans;
    }

    vector<int> rightmax(vector<int>& nums) {
        vector<int> ans(nums.size(), -1);
        stack<int> st;

        for (int i = nums.size() - 1; i >= 0; i--) {
            while (!st.empty() && nums[st.top()] <= nums[i]) {
                st.pop();
            }

            if (!st.empty()) {
                ans[i] = st.top();
            }
            st.push(i);
        }

        return ans;
    }

    bool increasingTriplet(vector<int>& nums) {
        int n = nums.size();

        vector<int> left = leftmin(nums);
        vector<int> right = rightmax(nums);

        for (int i = 0; i < n; i++) {
            if (left[i] != -1 && right[i] != -1 && nums[left[i]] < nums[i] && nums[i] < nums[right[i]]) {
                return true;
            }
        }

        return false;
    }
};
