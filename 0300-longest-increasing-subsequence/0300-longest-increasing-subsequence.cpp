class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        

        vector<int>temp;
        int n=nums.size();

        temp.push_back(nums[0]);

        for(int i=1;i<n;i++){
            int curr=nums[i];
            if(curr>temp.back()){
                temp.push_back(curr);
            }
            else{
                int position=lower_bound(temp.begin(),temp.end(),curr)-temp.begin();
                temp[position]=nums[i];
            }
        }
        return temp.size();
    }
};