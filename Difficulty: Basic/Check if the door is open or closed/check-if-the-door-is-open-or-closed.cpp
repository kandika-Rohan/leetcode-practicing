//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
  public:
    int *checkDoorStatus(int N) {
        int *arr=new int[N];
        for(int i=0;i<N;i++)
        {
            arr[i]=0;
        }
        for(int i=0;i<N;i++)
        {
            int j=i;
            while(j<N)
            {
                if(arr[j]==0)arr[j]=1;
                else arr[j]=0;
                j=j+i+1;
            }
        }
        return arr;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;

        Solution ob;
        int* ptr = ob.checkDoorStatus(N);
        for(int i=0 ; i<N ; i++)
            cout<<ptr[i]<<" ";
        cout<<endl;
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends