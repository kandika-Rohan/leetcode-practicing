class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        unordered_map<int,int>map;
        for(auto it:nums){
            if(it == val){
                continue;
            }
            map[it]++;
        }
        nums.clear();

        for(auto it:map){
            int val=it.first;
            int cnt=it.second;
            while(cnt){
                nums.push_back(val);
                cnt--;
            }
        }
        return nums.size();
    }
};