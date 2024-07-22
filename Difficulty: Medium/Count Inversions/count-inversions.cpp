//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends



class Solution {
public:
    // Function to merge two sorted subarrays and count inversions
    long long int merge(long long arr[], int low, int mid, int high) {
        int left = low;
        int right = mid + 1;
        std::vector<long long> temp(high - low + 1);
        int i = 0;
        long long int cnt = 0;

        while (left <= mid && right <= high) {
            if (arr[left] <= arr[right]) {
                temp[i++] = arr[left++];
            } else {
                temp[i++] = arr[right++];
                cnt += (mid - left + 1); // Count the inversions
            }
        }

        while (left <= mid) {
            temp[i++] = arr[left++];
        }

        while (right <= high) {
            temp[i++] = arr[right++];
        }

        for (int j = 0; j < temp.size(); ++j) {
            arr[low + j] = temp[j];
        }

        return cnt;
    }

    long long int mergesort(long long arr[], int low, int high) {
        long long int cnt = 0;
        if (low < high) {
            int mid = low + (high - low) / 2;
            cnt += mergesort(arr, low, mid);
            cnt += mergesort(arr, mid + 1, high);
            cnt += merge(arr, low, mid, high);
        }
        return cnt;
    }

    long long int inversionCount(long long arr[], int n) {
        return mergesort(arr, 0, n - 1);
    }
};



//{ Driver Code Starts.

int main() {

    long long T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        long long A[N];
        for (long long i = 0; i < N; i++) {
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A, N) << endl;
    }

    return 0;
}

// } Driver Code Ends