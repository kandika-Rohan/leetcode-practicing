class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        
        int n=graph.size();
        vector<int>adj[n];
        vector<int>outdegree(n,0);
        for(int i=0;i<n;i++){
            for(auto it:graph[i]){
                adj[it].push_back(i);
                outdegree[i]++;
            }
        }


        queue<int>q;
        for(int i=0;i<n;i++){
            if(outdegree[i] == 0){
                q.push(i);
            }
        }

        vector<int>ans;

        while(!q.empty()){
            int i=q.front();
            q.pop();
            ans.push_back(i);
            for(auto it:adj[i]){
                outdegree[it]--;
                if(outdegree[it] == 0){
                    q.push(it);
                }
            }
        }
        sort(ans.begin(),ans.end());

        return ans;
       
    }
};