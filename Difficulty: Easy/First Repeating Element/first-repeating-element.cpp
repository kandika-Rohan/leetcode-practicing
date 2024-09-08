//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template in C++

class Solution {
  public:
    // Function to return the position of the first repeating element.
    int firstRepeated(vector<int> &arr) {
        // code here
     unordered_map<int, int> map;  
    int min_index = -1;           // To track the smallest index of a repeating element

    // Traverse the array and store the first occurrence of each element
    for (int i = arr.size() - 1; i >= 0; i--) {
        if (map.find(arr[i]) != map.end()) {
            // If the element is already in the map, update min_index to the current index
            min_index = i;
        } else {
            // Otherwise, store the current index (0-based) for the element
            map[arr[i]] = i;
        }
    }

    // Return the 1-based index if a repeating element is found, otherwise -1
    return (min_index == -1) ? -1 : min_index + 1;
    }
};

//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input); // Read the entire line for the array elements
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        cout << ob.firstRepeated(arr) << endl;
    }

    return 0;
}

// } Driver Code Ends