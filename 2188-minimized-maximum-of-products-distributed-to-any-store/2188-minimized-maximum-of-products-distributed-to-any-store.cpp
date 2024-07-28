class Solution {
public:
    bool check(vector<int> quantities, int mid, int store, int n){
        int s = 0;
        for(int i = 0; i < n; i++){
            int quan = quantities[i];
            //distributing predecting quantities mid to store s, incresing s++
            while(quan > 0){
                if(quan >= mid){
                    quan -= mid;
                    s++;
                }
                else{
                    s++;
                    quan = 0;
                }
                // when more store required than given store
                if(s > store) return false;
            }
        }
        return true;
    }
    int minimizedMaximum(int store, vector<int>& quantities) {
        int n = quantities.size();
        int right;
        for(int i = 0; i < n; i++){
            right = max(right, quantities[i]);
        }
        int res = -1;
        int left = 0;
        while(left <= right){
            int mid = left + (right - left) / 2;
            if(check(quantities, mid , store, n)){
                res = mid;
                right = mid - 1;
            }
            else{
                left = mid + 1;
            }
        }
        return res;
    }
};