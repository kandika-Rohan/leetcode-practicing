class Solution {
public:
    string reverseVowels(string s) {
        int l = 0;
        int r = s.size() - 1;
        set<char> st = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};

        while (l < r) {
            if (st.find(s[l]) != st.end() && st.find(s[r]) != st.end()) {
                swap(s[l], s[r]);
                l++;
                r--;
            } else if (st.find(s[l]) != st.end()) {
                r--;
            } else if (st.find(s[r]) != st.end()) {
                l++;
            } else {
                l++;
                r--;
            }
        }
        return s;
    }
};
