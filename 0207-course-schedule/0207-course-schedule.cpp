class Solution {
public:
    bool dfs(int node,vector<int>&pathvis,vector<int>&vis,vector<int>adj[]){
        vis[node]=1;
        pathvis[node]=1;
        for(auto it:adj[node]){
            if(!vis[it]){
                if(dfs(it,pathvis,vis,adj)==true){
                    return true;
                }
            }
            else if(pathvis[it]==1){
                return true;
            }
        }
       pathvis[node]=0;
       return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        vector<int>adj[numCourses];
        for(auto it:prerequisites){
            int u=it[0];
            int v=it[1];
            adj[v].push_back(u);
        }

        vector<int>vis(numCourses,0);
        vector<int>pathvis(numCourses,0);
        for(int i=0;i<numCourses;i++){
            if(!vis[i]){
                if(dfs(i,pathvis,vis,adj) == true){
                    //if cycle we are not able to complete the course 

                    return false;
                }
            }
        }
        //if no cycle and no conflict then we can complete the coursees
        return true;
    }
};