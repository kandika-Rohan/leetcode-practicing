class Solution {
public:
    long long maxSum(vector<vector<int>>& grid, vector<int>& limits, int k) {
        
        priority_queue<pair<int,int>>pq;

        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                pq.push({grid[i][j],i});
            }
        }

        long long sum=0;

        while(k != 0 && !pq.empty()){

            auto it=pq.top();
            pq.pop();

            int val=it.first;
            int ind=it.second;

            if(limits[ind]>0){

            limits[ind]=limits[ind]-1;

            sum+=val;
            k=k-1;

            }
        }
        return sum;
    }
};