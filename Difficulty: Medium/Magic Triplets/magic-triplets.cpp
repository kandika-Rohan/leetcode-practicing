//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int n = arr.size();
        
        int count = 0;

        for (int j = 1; j < n - 1; j++) {  
            
            int count_left = 0, count_right = 0;

            for (int i = 0; i < j; i++) {
                if (arr[i] < arr[j]) count_left++;
            }

          
            for (int k = j + 1; k < n; k++) {
                if (arr[k] > arr[j]) count_right++;
            }

            
            count += count_left * count_right;
        }

        return count;
    }
};



//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)cin >> nums[i];
		Solution ob;
		int ans = ob.countTriplets(nums);
		cout << ans << "\n";
	
cout << "~" << "\n";
}  
	return 0;
}
// } Driver Code Ends