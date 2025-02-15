//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int* greaterElement(int arr[], int n);

int main()
{
    int t,n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        int *b;
        b = greaterElement(arr, n);
        for(int i=0;i<n;i++){
            if(b[i] == -10000000)
                cout << "_ ";
            else
                cout << b[i] << " ";
        }
        cout<<endl;   
        
    
cout << "~" << "\n";
}
    return 0;
}

// } Driver Code Ends


int* greaterElement(int arr[], int n) {
    
  set<int>st;
    
    for(int i=0 ;i<n ;i++){
        st.insert(arr[i]);
    }
    for(int i=0 ;i< n ;i++){
        auto it=st.find(arr[i]);
        it++;
        if(it!=st.end()){
            arr[i]=*it;
        }
        else {
            arr[i]=-10000000;
        }
    }
    return arr;
    
}

