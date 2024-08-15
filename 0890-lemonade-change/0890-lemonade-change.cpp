class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        
        // if(bills[0] != 5)return false;
        int fivecnt=0;
        int tencnt=0;

        for(auto it:bills){

            if(it == 5){
                fivecnt++;
            }
            else if(it == 10){
                tencnt++;
                if(fivecnt>=1){
                    fivecnt-=1;
                }
                else{
                    return false;
                }
            }
            else{
                //this is the case of when we get the 20 rupees coins
                if(tencnt>=1 && fivecnt>=1){
                    tencnt-=1;
                    fivecnt-=1;
                }
                else if(fivecnt>=3){
                    fivecnt-=3;
                }
                else{
                    return false;
                }
            }
        }
        return true;
    }
};