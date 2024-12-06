class Solution {
public:
    string minWindow(string a, string b) {
    int hash[256] = {0};
    int minlen = INT_MAX;
    int i = 0;
    int start = -1;

    for (char ch : b) {
        hash[ch]++;
    }

    int n = a.size();
    int m = b.size();
    int count = 0;

    for (int j = 0; j < n; j++) {
        if (hash[a[j]] > 0) {
            count++;
        }
        hash[a[j]]--;

        while (count == m) {
            if (minlen > j - i + 1) {
                minlen = j - i + 1;
                start = i;
            }

            hash[a[i]]++;
            if (hash[a[i]] > 0) {
                count--;
            }
            i++;
        }
    }

    return start == -1 ? "" : a.substr(start, minlen);
    }
};