class Solution {
public:
    vector<int> leftsmaller(vector<int>& arr, int n) {
        vector<int> ans(n, 0);
        stack<int> st;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }
            ans[i] = st.empty() ? i + 1 : i - st.top();  // distance from the previous smaller element
            st.push(i);
        }
        return ans;
    }
    
    vector<int> rightsmaller(vector<int>& arr, int n) {
        vector<int> ans(n, 0);
        stack<int> st;
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] > arr[i]) {
                st.pop();
            }
            ans[i] = st.empty() ? n - i : st.top() - i;  // distance to the next smaller element
            st.push(i);
        }
        return ans;
    } 
    
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        const int MOD = 1e9 + 7;
        vector<int> left = leftsmaller(arr, n);
        vector<int> right = rightsmaller(arr, n);
        int sum = 0;
        for (int i = 0; i < n; i++) {
            long long numberofSubarrays = ((long long)left[i] * right[i]) % MOD;  // Calculate subarray count
            sum = (sum + numberofSubarrays * arr[i]) % MOD;
        }
        return sum;
    }
};
