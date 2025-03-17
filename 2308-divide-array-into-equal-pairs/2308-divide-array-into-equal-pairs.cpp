class Solution {
public:
    bool divideArray(vector<int>& nums) {
        
        unordered_map<int,int>map;

        for(auto it:nums){
            map[it]++;
        }
        int n=nums.size();
        int cnt=0;
        for(auto it:map){
            
            int val=it.first;
            int count=it.second;
            cout<<val<<" "<<count<<endl;
            if(count<2){
                return false;
            }
            cnt+=(count/2);
        }

        return cnt>=n/2;
    }
};