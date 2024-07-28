class Solution {
public:

   bool ispossible(int mid,vector<int>& weights, int days){
         int day=1;
         int sum=0;
         for(int i=0;i<weights.size();i++){
            sum+=weights[i];
            if(sum>mid){
                day++;
                sum=weights[i];
                if(day>days){
                    return false;
                }
            }
         }
         return day<=days;
   }
    int shipWithinDays(vector<int>& weights, int days) {
        int r=accumulate(weights.begin(),weights.end(),0);
        int l=*max_element(weights.begin(),weights.end());

        int ans=-1;
        while(l<=r){
            int mid=(l+r)/2;
            if(ispossible(mid,weights,days)){
                r=mid-1;
                ans=mid;
            }
            else{
                l=mid+1;
            }
        }
        return ans;
    }
};