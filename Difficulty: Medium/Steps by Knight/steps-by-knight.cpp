//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends



class Solution 
{
    public:
    //Function to find out minimum steps Knight needs to reach target position.
	int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int N)
	{
	    // Code here
	    
	    queue<pair<int,pair<int,int>>>q;
	    
	    int delrow[]={-2,-1,1,2,2,1,-1,-2};
	    int delcol[]={1,2,2,1,-1,-2,-2,-1};
	    
	    int i=KnightPos[0];
	    int j=KnightPos[1];
	    
	    int src=TargetPos[0];
	    int dst=TargetPos[1];
	    
	    // Fixing bounds to ensure valid positions
	    if(i < 1 || j < 1 || src < 1 || dst < 1 || i > N || j > N || src > N || dst > N){
	        return -1;
	    }
	    
	    vector<vector<int>>vis(N+1,vector<int>(N+1,0));
	    
	    q.push({0,{i,j}});
	    
	    vis[i][j]=1;
	    
	    while(!q.empty()){
	        
	        auto it=q.front();
	        q.pop();
	        int tm=it.first;
	        int r=it.second.first;
	        int c=it.second.second;
	        
	        if(r == src && c == dst){
	            return tm;
	        }
	        
	        for(int i=0;i<8;i++){
	            int nrow=r+delrow[i];
	            int ncol=c+delcol[i];
	            
	            // Fixing the range for 1-based indexing
	            if(nrow >=1 && nrow <= N && ncol >=1 
	            && ncol <= N && !vis[nrow][ncol]){
	                vis[nrow][ncol]=1;
	                q.push({tm+1,{nrow,ncol}});
	            }
	        }
	    }
	    
	    return -1;
	}
};




//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		vector<int>KnightPos(2);
		vector<int>TargetPos(2);
		int N;
		cin >> N;
		cin >> KnightPos[0] >> KnightPos[1];
		cin >> TargetPos[0] >> TargetPos[1];
		Solution obj;
		int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends