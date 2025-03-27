//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    Solution() {}

    stack<int> st;
    int mini = INT_MAX;

    void push(int x) {
        if (st.empty()) {
            mini = x;
            st.push(x);
        } else {
            if (x < mini) {
                st.push(2 * x - mini);
                mini = x;
            } else {
                st.push(x);
            }
        }
    }

    void pop() {
        if (!st.empty()) {
            int x = st.top();
            st.pop();
            if (x < mini) {
                mini = 2 * mini - x;
            }
        }
    }

    int peek() {
        if (st.empty()) return -1;
        return (st.top() < mini) ? mini : st.top();
    }

    int getMin() {
        return st.empty() ? -1 : mini;
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int q;
        cin >> q;

        Solution ob;

        while (q--) {
            int qt;
            cin >> qt;

            if (qt == 1) {
                // push
                int att;
                cin >> att;
                ob.push(att);
            } else if (qt == 2) {
                // pop
                ob.pop();
            } else if (qt == 3) {
                // peek
                cout << ob.peek() << " ";
            } else if (qt == 4) {
                // getMin
                cout << ob.getMin() << " ";
            }
        }
        cout << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends