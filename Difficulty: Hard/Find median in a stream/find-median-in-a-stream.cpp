//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends
class Solution
{
    public:
    //Function to insert heap.
    int n=0;
    double median;
    priority_queue<int>maxheap;
    priority_queue<int,vector<int>,greater<int>>minheap;
    
    void insertHeap(int &x)
    {
        if(!maxheap.empty() && maxheap.top()>x){
            maxheap.push(x);
            if(maxheap.size()>minheap.size()+1){
                minheap.push(maxheap.top());
                maxheap.pop();
            }
        }
            else{
                minheap.push(x);
                if(minheap.size()>maxheap.size()+1){
                    maxheap.push(minheap.top());
                    minheap.pop();
                }
            }
        n++;
    }
    double getMedian()
    {
        if(n & 1){
            median=minheap.size()>maxheap.size()?minheap.top():maxheap.top();
        }
        else{
            median=minheap.top()+maxheap.top();
            median/=2;
            
        }
        return median;
    }
};


//{ Driver Code Starts.

int main()
{
    int n, x;
    int t;
    cin>>t;
    while(t--)
    {
    	Solution ob;
    	cin >> n;
    	for(int i = 1;i<= n; ++i)
    	{
    		cin >> x;
    		ob.insertHeap(x);
    	    cout << floor(ob.getMedian()) << endl;
    	}
    }
	return 0;
}
// } Driver Code Ends