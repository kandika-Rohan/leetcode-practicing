class Solution {
public:
    bool check(vector<int>& nums) {
        
        vector<int>arr=nums;

        sort(begin(arr),end(arr));

        for(int i=0;i<nums.size();i++){
            rotate(begin(arr),begin(arr)+1,end(arr));
            if(nums == arr){
                return true;
            }
        }

        return false;
    }
};