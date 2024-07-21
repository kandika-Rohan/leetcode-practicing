#include <vector>
#include <queue>
#include <set>

using namespace std;

class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> ans;
        int n1 = nums1.size();
        int n2 = nums2.size();
        
        // Edge cases
        if (n1 == 0 || n2 == 0 || k == 0) return ans;

        // Min-heap to store pairs of sums and their corresponding indices
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> q;
        set<pair<int, int>> st;
        
        // Initialize the heap with the first pair (0,0)
        q.push({nums1[0] + nums2[0], {0, 0}});
        st.insert({0, 0});

        // Extract k smallest pairs
        while (k-- > 0 && !q.empty()) {
            auto node = q.top();
            q.pop();

            int row = node.second.first;
            int col = node.second.second;
            ans.push_back({nums1[row], nums2[col]});
            
            // If there's a next row element, add it to the heap
            if (row + 1 < n1 && st.find({row + 1, col}) == st.end()) {
                q.push({nums1[row + 1] + nums2[col], {row + 1, col}});
                st.insert({row + 1, col});
            }
            
            // If there's a next column element, add it to the heap
            if (col + 1 < n2 && st.find({row, col + 1}) == st.end()) {
                q.push({nums1[row] + nums2[col + 1], {row, col + 1}});
                st.insert({row, col + 1});
            }
        }
        
        return ans;
    }
};
