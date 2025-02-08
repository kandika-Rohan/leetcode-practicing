class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        
        int n=candies.size();

        vector<int>left(n),right(n);

        left[0]=candies[0];
        right[n-1]=candies[n-1];


        for(int i=1;i<n;i++){
            
            left[i]=max(left[i-1],candies[i]);
        }

        for(int i=n-2;i>=0;i--){
            right[i]=max(right[i+1],candies[i]);
        }
        

        vector<bool>ans(n);

        for(int i=0;i<n;i++){

            cout<<left[i]<<" "<<right[i]<<endl;

            int val=extraCandies+candies[i];



            if(val>=left[i] && val >= right[i]){
                ans[i]=true;
            }
            else{
                ans[i]=false;
            }
        }
        return ans;
    }
};