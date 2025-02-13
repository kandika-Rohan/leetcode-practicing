class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        
        priority_queue<long long,vector<long long>,greater<long long>>q;

        int n=nums.size();

        if(n<=1){
            return 0;
        }

        for(auto it:nums){
            q.push(it);
        }
        int count=0;
        while(q.top()<k && q.size()>=2 && !q.empty()){

            long long first=q.top();
            q.pop();
            long long second=q.top();
            q.pop();
            long long value=first*2+second;
            q.push(value);
            count++;
        }
        return count;

    }
};