//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

#include <vector>
#include <algorithm>

class Solution {
public:
    void merge(int low, int mid, int high, std::vector<int>& nums) {
        int s = low;
        int e = mid + 1;
        std::vector<int> temp;
        while (s <= mid && e <= high) {
            if (nums[s] <= nums[e]) {
                temp.push_back(nums[s]);
                s++;
            } else {
                temp.push_back(nums[e]);
                e++;
            }
        }
        
        while (s <= mid) {
            temp.push_back(nums[s++]);
        }
        while (e <= high) {
            temp.push_back(nums[e++]);
        }
        
        int i = low;
        for (auto it : temp) {
            nums[i] = it;
            i++;
        }
    }

    void mergesort(int low, int high, std::vector<int>& nums) {
        if (low >= high) {
            return;
        }
        int mid = (low + high) / 2;
        mergesort(low, mid, nums);
        mergesort(mid + 1, high, nums);
        merge(low, mid, high, nums);
    }

    void sortLastMelements(std::vector<int>& nums, int n, int m) {
   
        mergesort(n, n + m - 1, nums);

    
        int i = 0, j = n, k = 0;
        std::vector<int> sorted(n + m);
        while (i < n && j < n + m) {
            if (nums[i] <= nums[j]) {
                sorted[k++] = nums[i++];
            } else {
                sorted[k++] = nums[j++];
            }
        }
        while (i < n) {
            sorted[k++] = nums[i++];
        }
        while (j < n + m) {
            sorted[k++] = nums[j++];
        }

        for (int i = 0; i < n + m; ++i) {
            nums[i] = sorted[i];
        }
    }
};



//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<int>nums(n+m);
		for(auto &i: nums)
			cin >> i;
		Solution obj;
		obj.sortLastMelements(nums, n, m);
		for(auto i: nums)
			cout << i << " ";
		cout << "\n";
	}
	return 0;
}
// } Driver Code Ends