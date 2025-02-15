//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    bool leapyear(int y){
        
        return ( (y%100 != 0 && y%4==0) || y%400 == 0);
    }
    int calDays(int d,int m,int y){
        
      int DM[]={0,31,28+leapyear(y),31,30,31,30,31,31,30,31,30,31};
      
      while(--y)d+=365+leapyear(y);
      
      return accumulate(DM,DM+m,d);
    }
    int noOfDays(int d1, int m1, int y1, int d2, int m2, int y2) {
        // code here
        return abs(calDays(d1,m1,y1) - calDays(d2,m2,y2));
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int d1,d2,m1,m2,y1,y2;
        
        cin>>d1>>m1>>y1;
        cin>>d2>>m2>>y2;

        Solution ob;
        cout << ob.noOfDays(d1,m1,y1,d2,m2,y2) << endl;
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends