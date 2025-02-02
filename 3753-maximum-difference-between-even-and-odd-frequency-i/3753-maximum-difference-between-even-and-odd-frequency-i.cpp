class Solution {
public:
    int maxDifference(string s) {
        

        vector<int>hash(26,0);

        for(auto it:s){
            hash[it-'a']++;
        }

        int maxevn=0,maxodd=0,mineven=INT_MAX,minodd=INT_MAX;

        for(auto it:hash){

            if(it & 1 && it != 0){
                maxodd=max(maxodd,it);
                minodd=min(minodd,it);
            }
            else if(it %2 == 0 && it != 0){
                maxevn=max(maxevn,it);
                mineven=min(mineven,it);
            }
        }

        int ans=INT_MIN;

        // ans=max(ans,(maxevn-maxodd));

        // ans=max(ans,(maxevn-minodd));

        ans=max(ans,(maxodd-mineven));

        ans=max(ans,(minodd-maxevn));

        ans=max(ans,(maxodd-maxevn));

        ans=max(ans,minodd-mineven);


       

        return ans;
    }
};