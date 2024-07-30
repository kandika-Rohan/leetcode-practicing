//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int shortestDistance(int N, int M, vector<vector<int>> A, int X, int Y) {
       queue<pair<int,pair<int,int>>>q;
       if(A[0][0] == 0 || A[X][Y] == 0){
           return -1;
       }
       vector<vector<int>>vis(N,vector<int>(M,0));
       vis=A;
       q.push({0,{0,0}});
       vis[0][0]=0;
       int delrow[]={-1,0,1,0};
       int delcol[]={0,1,0,-1};
       while(!q.empty()){
           auto node=q.front();
           q.pop();
           int dist=node.first;
           int row=node.second.first;
           int col=node.second.second;
           if(row == X && col == Y ){
               return dist;
           }
           for(int i=0;i<4;i++){
               int nrow=row+delrow[i];
               int ncol=col+delcol[i];
               if(nrow>=0 && nrow <N && ncol >=0 && ncol < M && vis[nrow][ncol]==1){
                   vis[nrow][ncol]=0;
                   q.push({dist+1,{nrow,ncol}});
               }
           }
       }
       return -1;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M, x, y;
        cin >> N >> M;
        vector<vector<int>> v(N, vector<int>(M));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) cin >> v[i][j];
        cin >> x >> y;
        Solution ob;
        cout << ob.shortestDistance(N, M, v, x, y) << "\n";
    }
}
// } Driver Code Ends