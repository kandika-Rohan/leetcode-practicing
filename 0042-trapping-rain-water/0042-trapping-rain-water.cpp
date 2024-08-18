class Solution {
public:
    vector<int>leftmax(vector<int>&arr,int n){
        vector<int>ans(n,0);
        int maxi=0;
        for(int i=0;i<n;i++){
            ans[i]=maxi;
            maxi=max(maxi,arr[i]);
        }

        return ans;
    }

    vector<int>rightmax(vector<int>&arr,int n){
        vector<int>ans(n,0);
        int maxi=0;
        for(int i=n-1;i>=0;i--){
            ans[i]=maxi;
            maxi=max(maxi,arr[i]);
        }
        return ans;
    }
    int trap(vector<int>& height) {
        int maxi=0;
        int n=height.size();

        vector<int>left=leftmax(height,n);
        vector<int>right=rightmax(height,n);

        for(int i=0;i<n;i++){
            int val=min(left[i],right[i]);
            cout<<val<<" ";
            if(val>height[i]){
                val-=height[i];
                maxi+=val;
            }
    
        }

        return maxi;
    }
};