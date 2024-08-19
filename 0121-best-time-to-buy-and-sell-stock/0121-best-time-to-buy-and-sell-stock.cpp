class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxprofit=0;

        int costprice=prices[0];

        for(int i=1;i<prices.size();i++){
            int sell=prices[i];
            int cost=sell-costprice;

            maxprofit=max(maxprofit,cost);
            costprice=min(costprice,sell);
        }
        return maxprofit;
    }
};