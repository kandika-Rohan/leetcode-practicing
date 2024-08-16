//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
    public:
    int delrow[4]={-1,0,1,0};
    int delcol[4]={0,1,0,-1};
    void dfs(int i,int j,vector<vector<int>>&matrix,vector<vector<int>>&vis
    ,int n,int m){
        vis[i][j]=1;
        queue<pair<int,int>>q;
        q.push({i,j});
        
        while(!q.empty()){
            int row=q.front().first;
            int col=q.front().second;
            q.pop();
            
            for(int i=0;i<4;i++){
                int nrow=delrow[i]+row;
                int ncol=delcol[i]+col;
                if(nrow>=0 && nrow <n && ncol>=0 && ncol<m && matrix[nrow][ncol]
                ==1 && !vis[nrow][ncol]){
                    vis[nrow][ncol]=1;
                    q.push({nrow,ncol});
                }
            }
        }
    }
    int closedIslands(vector<vector<int>>& matrix, int n, int m) {
        // Code here
        
        vector<vector<int>>vis(n,vector<int>(m,0));
        
        for(int i=0;i<m;i++){
            if(matrix[0][i] == 1 && !vis[0][i]){
                dfs(0,i,matrix,vis,n,m);
            }
            if(matrix[n-1][i] ==1 && !vis[n-1][i]){
                dfs(n-1,i,matrix,vis,n,m);
            }
        }
        
        for(int i=0;i<n;i++){
            if(matrix[i][0] == 1 && !vis[i][0]){
                dfs(i,0,matrix,vis,n,m);
            }
            if(matrix[i][m-1] ==1 && !vis[i][m-1]){
                dfs(i,m-1,matrix,vis,n,m);
            }
        }
        
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && matrix[i][j] ==1){
                    count++;
                    
                    dfs(i,j,matrix,vis,n,m);
                }
            }
        }
        
        return count;
    }
};

//{ Driver Code Starts.
int main() {
	int t;
	cin>>t;
	while(t--)
	{
        int N, M;
        cin >> N >> M;
        vector<vector<int>>matrix(N, vector<int>(M, 0));
        for(int i=0; i<N; i++)
            for(int j=0; j<M; j++)
                cin >> matrix[i][j];
                
        Solution obj;
        int ans = obj.closedIslands(matrix, N, M);
        cout << ans << "\n";
    }
	
	return 0;
	
}


// } Driver Code Ends