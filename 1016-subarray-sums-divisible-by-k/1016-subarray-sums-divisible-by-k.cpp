class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        mp[0]++;
        int s=0;int count=0;
        for(auto it:nums){
            s=(s+it%k+k)%k;
            count+=mp[s];
            mp[s]++;
        }
        return count;
    }
};