class Solution {
public:
    bool divideArray(vector<int>& nums) {
        unordered_map<int,int>map;
        for(auto it:nums){
            map[it]++;
        }

        int n=nums.size();
        int val=n/2;
        int sum=0;
        for(auto it:map){
            int val=it.second;
            if(val % 2 !=0){
                return false;
            }
        }
        return true;
    }
};