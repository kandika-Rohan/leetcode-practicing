class Solution {
public:
   void merge(vector<int>&nums,int low,int mid,int high){
    int start=low;int end=mid+1;
    vector<int>temp;;
    while(start<=mid && end <=high){
        if(nums[start]<=nums[end]){
            temp.push_back(nums[start]);
            start++;
        }
        else{
            temp.push_back(nums[end]);
            end++;
        }
    }
    while(start<=mid){
        temp.push_back(nums[start]);
        start++;
    }
       while(end<=high){
        temp.push_back(nums[end]);
        end++;
    }
    int i=low;
    for(auto it:temp){
        nums[i]=it;
        i++;
    }
   }
    void mergesort(vector<int>&nums,int low,int high){
        if(low>=high){
            return;
        }
        int mid=low + (high-low)/2;
        mergesort(nums,low,mid);
        mergesort(nums,mid+1,high);
        merge(nums,low,mid,high);
    }
    vector<int> sortArray(vector<int>& nums) {
        int n=nums.size();
        mergesort(nums,0,n-1);
        return nums;
    }
};