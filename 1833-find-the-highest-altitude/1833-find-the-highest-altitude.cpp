class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        

        int val=0;
        int maxi=-1e9;

        for(auto it:gain){
            val=val+it;
            maxi=max(maxi,val);
        }
        return maxi<0?0:maxi;
    }
};