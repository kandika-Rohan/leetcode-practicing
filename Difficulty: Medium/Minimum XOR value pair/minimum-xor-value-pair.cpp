//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++


class TRIE {
private:
    struct trie {
        trie *links[2];

        trie() {
            fill(begin(links), end(links), nullptr);
        }
    };

public:
    trie *root;

    TRIE() {
        root = new trie();
    }

    void insert(int num) {
        trie *node = root;

        for (int i = 31; i >= 0; i--) {
            int val = (num >> i) & 1;

            if (node->links[val] == nullptr) {
                node->links[val] = new trie();
            }

            node = node->links[val];
        }
    }

    int minimum_XR_value(int num) {
        trie *node = root;
        int result = 0;

        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;

            // Try to follow the path to minimize XOR
            if (node->links[bit]) {
                node = node->links[bit];
            } else {
                // If the preferred bit doesn't exist, take the other path
                result |= (1 << i); // Add the difference to the result
                node = node->links[!bit];
            }
        }

        return result;
    }
};

class Solution {
public:
    int minxorpair(int N, int arr[]) {
        TRIE *t = new TRIE();
        int minXOR = INT_MAX;

        // Insert the first element before processing
        t->insert(arr[0]);

        // Find the minimum XOR pair
        for (int i = 1; i < N; i++) {
            // Calculate XOR with the existing trie elements
            int currXOR = t->minimum_XR_value(arr[i]);
            minXOR = min(minXOR, currXOR);

            // Insert the current element into the trie
            t->insert(arr[i]);
        }

        return minXOR;
    }
};





//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, X;
        cin >> N;
        int arr[N];
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }

        Solution ob;
        cout << ob.minxorpair(N, arr) << endl;
    
cout << "~" << "\n";
}
    return 0; 
} 

// } Driver Code Ends