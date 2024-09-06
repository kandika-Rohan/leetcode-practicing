class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int maxi=0;
        int buy=prices[0];
        for(int i=1;i<prices.size();i++){
            int sell=prices[i];
            int cost=sell-buy;
            maxi=max(maxi,cost);
            buy=min(buy,prices[i]);
        }
        return maxi;
    }
};