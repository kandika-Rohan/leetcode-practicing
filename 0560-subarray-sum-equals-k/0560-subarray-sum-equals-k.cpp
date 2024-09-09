class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>map;
        int cnt=0;
        map[cnt]=1;
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            cnt+=map[sum-k];
            map[sum]++;
        }
        return cnt;
    }
};