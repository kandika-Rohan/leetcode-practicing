//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution 
{
    public:
    //Function to find the minimum number of swaps required to sort the array. 
	int minSwaps(vector<int>&nums)
	{
	    // Code here
	    unordered_map<int,int>map;
	    
	    vector<int>val=nums;
	    
	    sort(val.begin(),val.end());
	    
	    for(int i=0;i<nums.size();i++){
	        
	        map[val[i]]=i;
	    }
	    
	    int cnt=0;
	    
	    for(int i=0;i<nums.size();i++){
	        
	        if(i != map[nums[i]]){
	            
	            int ind=map[nums[i]];
	            swap(nums[i],nums[ind]);
	            i--;
	            cnt++;
	        }
	    }
	    
	    return cnt;
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
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution obj;
		int ans = obj.minSwaps(nums);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends