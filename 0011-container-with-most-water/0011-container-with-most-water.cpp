class Solution {
public:
    int maxArea(vector<int>& height) {
        int l=0;
        int r=height.size()-1;
        int ans=0;
        while(l<r){
            int width=r-l;
            int val=min(height[r],height[l]);
            ans=max(ans,val*width);
            if(height[l] < height[r]){
                l+=1;
            }
            else {
                r-=1;
            }
        }
        return ans;
    }
};