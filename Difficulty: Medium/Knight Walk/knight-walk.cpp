//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	int minStepToReachTarget(vector<int>&KnightPos,
	vector<int>&TargetPos, int N){
	    // Code here
	    
	    
	    vector<vector<int>>vis(N+1,vector<int>(N+1,0));
	    
	    
	    using p=pair<int,pair<int,int>>;
	    
	    queue<p>q;
	    
	    int s=KnightPos[0];
	    
	    int e=KnightPos[1];
	    
	    q.push({0,{s,e}});
	    
	    vis[s][e]=1;
	   
	    int dr=TargetPos[0];
	    int dc=TargetPos[1];
	    
	    int delrow[8]={2,2,-2,-2,1,1,-1,-1};
	    
	    int delcol[8]={1,-1,1,-1,2,-2,2,-2};
	    
	    while(!q.empty()){
	        
	        auto it=q.front();
	        q.pop();
	        
	        int steps=it.first;
	        int r=it.second.first;
	        int c=it.second.second;
	        
	        if(r == dr && c== dc){
	            return steps;
	        }
	        
	        for(int i=0;i<8;i++){
	            int nrow=r+delrow[i];
	            int ncol=c+delcol[i];
	            
	            if(nrow >=0 && nrow < N+1 && 
	            ncol >=0 && ncol < N+1 && !vis[nrow][ncol]){
	                vis[nrow][ncol]=1;
	                q.push({steps+1,{nrow,ncol}});
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