//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	vector<int> DistinctSum(vector<int>nums){
	    // Code here
	    
	    int totalSum=accumulate(begin(nums),end(nums),0);
	    
	    int n=nums.size();
	    
	    vector<vector<bool>>dp(n,vector<bool>(totalSum,false));
	    
	    for(int i=0;i<n;i++){
	        dp[i][0]=true;
	    }
	    
	    if(nums[0]<=totalSum){
	        dp[0][nums[0]]=true;
	    }
	    
	    for(int i=1;i<n;i++){
	        for(int target=1;target<=totalSum;target++){
	            bool nottake=dp[i-1][target];
	            bool take=false;
	            if(target>=nums[i]){
	                take=dp[i-1][target-nums[i]];
	            }
	            dp[i][target]=take or nottake;
	        }
	    }
	    vector<int>ans;
	    
	    ans.push_back(0);
	    
	    for(int i=1;i<=totalSum;i++){
	        if(dp[n-1][i] == true){
	            ans.push_back(i);
	        }
	    }
	    
	    return ans;
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
		Solution obj;
		vector<int> ans = obj.DistinctSum(nums);
		for(auto i: ans)cout << i << " ";
		cout << "\n";
	
cout << "~" << "\n";
}
	return 0;
}

// } Driver Code Ends