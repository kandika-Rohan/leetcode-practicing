class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int mini = INT_MAX, cnt = 0;

        
        for (int i = 0; i < k; i++) {
            if (blocks[i] == 'B') {
                cnt++;
            }
        }
        mini = min(mini, k - cnt);

       
        for (int i = k; i < blocks.size(); i++) {
            if (blocks[i] == 'B') cnt++;  
            if (blocks[i - k] == 'B') cnt--; 

            mini = min(mini, k - cnt); 
        }
        return mini;
    }
};
