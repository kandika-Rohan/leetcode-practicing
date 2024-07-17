class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int fiveBills=0;
        int tenBills=0;
        for(auto bill:bills){
            //case where customer with bill 5 
            if(bill==5){
                fiveBills++;
            }
            //case where customer with bill 10
            else if(bill==10){
                if(fiveBills>=1){
                    fiveBills--;
                    tenBills++;
                }
                else{
                    return false;
                }
            }
            //case where customer with bill 20
            else {
                if(tenBills>=1 && fiveBills>=1){
                    fiveBills--;
                    tenBills--;
                }
                else if(fiveBills>=3){
                    fiveBills-=3;
                }
                else{
                    return false;
                }
            }
        }
        return true;
    }
};