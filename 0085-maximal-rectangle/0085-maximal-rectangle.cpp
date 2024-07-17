#include<stack>
class Solution {
public:
    // finding the leftsmaller element of the every element;
    vector<int>leftsmaller(vector<int>&heights){
        stack<int>st;
        int n=heights.size();
        vector<int>ans(n,-1);
        for(int i=0;i<n;i++){
            while(!st.empty() && heights[st.top()]>=heights[i]){
                st.pop();
            }
            if (!st.empty()) { 
                ans[i]=st.top(); 
            }
            st.push(i);
        }
        return ans;
    }

    //finding the rightsmaller elelent of every elemet;

    vector<int>rightsmaller(vector<int>&heights){
        stack<int>st;
        int n=heights.size();
        vector<int>ans(n,n);
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && heights[st.top()]>=heights[i]){
                st.pop();
            }
            if (!st.empty()) { 
                ans[i]=st.top(); 
            }
            st.push(i);
        }
        return ans;

    }

    int largetstRectangle(vector<int>&heights){

        vector<int>lsmaller=leftsmaller(heights);
        vector<int>rsmaller=rightsmaller(heights);

        int maxi=INT_MIN;

        for(int i=0;i<heights.size();i++){
            
            int breadth=rsmaller[i]-lsmaller[i]-1;
            int length=heights[i];

            maxi=max(maxi,length*breadth);
        }

        return maxi;

    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        

        vector<int>heights(matrix[0].size(),0);
        int maxi=INT_MIN;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){

                if(matrix[i][j]=='1'){
                    heights[j]++;
                }
                else{
                    heights[j]=0;
                }
            }
            maxi=max(maxi,largetstRectangle(heights));
        }
        return maxi;
    }
};