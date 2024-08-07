//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        // code here
        vector<int>distance(N,1e9);
        distance[0]=0;
        for(int i=0;i<N-1;i++){
            for(auto it:edges){
                int u=it[0];
                int v=it[1];
                int wt=it[2];
                if(distance[u]!= 1e9 && wt+distance[u]<distance[v]){
                    distance[v]=wt+distance[u];
                }
            }
        }
        for(auto it:edges){
                int u=it[0];
                int v=it[1];
                int wt=it[2];
                if(distance[u]!= 1e9 && wt+distance[u]<distance[v]){
                    return {-1};
                }
            }
            for(int i=0;i<N;i++){
                if(distance[i]==1e9)distance[i]=-1;
            }
        return distance;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends