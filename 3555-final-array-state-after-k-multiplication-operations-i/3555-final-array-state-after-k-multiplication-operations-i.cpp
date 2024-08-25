class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
    
       for(int i=0;i<nums.size();i++){
        q.push({nums[i],i});
       }

        while(k != 0){
            auto x=q.top();
            q.pop();
            int val=x.first;
            int ind=x.second;
            val*=multiplier;
            q.push({val,ind});
            k--;
        }

        while(!q.empty()){
            auto x=q.top();
            q.pop();
            int ind=x.second;
            int val=x.first;
            nums[ind]=val;
        }
        return nums;
    }
};