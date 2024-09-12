class Solution {
public: 
    bool dfs(int node,vector<int>&vis,vector<int>&pathvis,vector<int>adj[],vector<int>&ans){
        vis[node]=1;
        pathvis[node]=1;
        for(auto it:adj[node]){
            if(!vis[it]){
                if(dfs(it,vis,pathvis,adj,ans)==true){
                    return true;
                }
            }
            else if(pathvis[it] ==1){
                return true;
            }
        }
        pathvis[node]=0;
        ans.push_back(node);
        return false;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        
        vector<int>adj[numCourses];
        for(auto it:prerequisites){
            int u=it[0];
            int v=it[1];
            adj[v].push_back(u);
        }

        vector<int>vis(numCourses,0),pathvis(numCourses,0);

        vector<int>ans;
        for(int i=0;i<numCourses;i++){
            if(!vis[i]){
                if(dfs(i,vis,pathvis,adj,ans) == true){
                    return {};
                }
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};