class Solution {
public:
    int f(string s, int k) {
        unordered_set<char> st = {'a', 'e', 'i', 'o', 'u'};
        int i = 0, sum = 0, maxi = 0;

        for (int j = 0; j < s.size(); j++) {

            if (st.find(s[j]) != st.end()) {

                sum++;
            }

            if ((j - i + 1) > k) {


                if (st.find(s[i]) != st.end()) {
                    
                    sum--;
                }

                i++;
            }

            maxi = max(maxi, sum);
        }
        return maxi;
    }

    int maxVowels(string s, int k) {
        return f(s, k);
    }
};
