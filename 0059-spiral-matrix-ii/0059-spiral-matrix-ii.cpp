class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int size=n*n;
        vector<vector<int>>ans(n,vector<int>(n,0));

        int top=0;
        int bottom=n-1;
        int left=0;
        int right=n-1;
        int k=1;
        while(top<=bottom && left <= right){
            
            for(int i=left;i<=right;i++){
                if(ans[top][i] == 0){
                    ans[top][i]=k++;
                }
            }
            top++;

            for(int i=top;i<=bottom;i++){
                if(ans[i][right] == 0){
                    ans[i][right]=k++;
                }
            }
            right--;

            if(left <= right){
                for(int i=right;i>=left;i--){
                    if(ans[bottom][i] == 0){
                        ans[bottom][i]=k++;
                    }
                }
                bottom --;
            }
            if(top <=bottom){
                for(int i=bottom ;i>=top;i--){
                    if(ans[i][left] == 0){
                        ans[i][left]=k++;
                    }
                }
                left++;
            }
        }
        return ans;

    }
};