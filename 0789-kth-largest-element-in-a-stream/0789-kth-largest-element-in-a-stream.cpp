class KthLargest {
public:
    priority_queue<int,vector<int>,greater<int>>minheap;
    int k;
    KthLargest(int k, vector<int>& nums) {
        this->k=k;
        for(auto it:nums)
        {
            minheap.push(it);
            if(minheap.size()>k)
            {
                minheap.pop();
            }
        }
    }
    int add(int val) {
        minheap.push(val);
        while(minheap.size()>k)
        {
            minheap.pop();
        }
        return minheap.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */