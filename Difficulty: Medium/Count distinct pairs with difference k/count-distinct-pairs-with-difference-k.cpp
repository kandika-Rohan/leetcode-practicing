//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	int TotalPairs(vector<int>num, int k){
        // Code here
        
        unordered_map<int ,int> mp;
        int ans =0;
        
        for(auto &x : num)
        ++mp[x];
        
        if(k ==0){
           
           for(auto &x: mp)
           if(x.second > 1)++ans;
           
           return ans;
        }
        
        for(auto &x : mp){
            
            if(mp.find(x.first+k) != mp.end())
            ++ans;
        }
        
        return ans;
    }

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, k;
		cin >> n >> k;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution ob;
		int ans = ob.TotalPairs(nums, k);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends