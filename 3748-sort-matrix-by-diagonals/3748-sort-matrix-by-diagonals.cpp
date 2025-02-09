class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        
        int n=grid.size();
        int m=grid[0].size();

        vector<int>v;

        for(int i=0;i<n;i++){


            v.push_back(grid[i][i]);
        }
        sort(begin(v),end(v),greater<int>());

        for(int i=0;i<n;i++){
            grid[i][i]=v[i];
        }
        v.clear();

        //lower diagnoal

        

        for(int i=1;i<n;i++){
            for(int j=0;j<n;j++){
            int i1=i,j1=j;
            vector<int>v;
            while(i1<n && j1<n){
            
            v.push_back(grid[i1][j1]);
            i1++;
            j1++;

            }
            sort(begin(v),end(v),greater<int>());
            i1=i,j1=j;
            int k=0;
            while(i1<n && j1<n){
            
            grid[i1][j1]=v[k++];
            i1++;
            j1++;

            }
        }
        }

        //upper diagnoal
for (int j = 1; j < n; j++) {  // Start from j = 1 to exclude the main diagonal
    int i1 = 0, j1 = j;
    vector<int> v;

    while (i1 < n && j1 < n) {
        v.push_back(grid[i1][j1]);
        i1++;
        j1++;
    }
    
    sort(begin(v), end(v));

    i1 = 0, j1 = j;
    int k = 0;

    while (i1 < n && j1 < n) {
        grid[i1][j1] = v[k++];
        i1++;
        j1++;
    }
}



      
  return grid;


    }
};