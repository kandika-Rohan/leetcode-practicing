class Solution {
public:
    long long countAtLeastMConsonants(const string &word, int m) {
        long long n = word.size();
        unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
        unordered_map<char, int> vowels_map;
        long long num_consonants = 0;
        long long ans = 0;
        long long l = 0, r = 0;

        while (r < n || l < n) {
            if (vowels_map.size() == 5 && num_consonants >= m) {
                ans += n - r + 1;
                if (vowels.find(word[l]) == vowels.end()) {
                    // It's a consonant
                    num_consonants--;
                } else {
                    vowels_map[word[l]]--;
                    if (vowels_map[word[l]] == 0) {
                        vowels_map.erase(word[l]);
                    }
                }
                l++;
            } else {
                if (r == n) {
                    break;
                }
                if (vowels.find(word[r]) == vowels.end()) {
                   
                    num_consonants++;
                } else {
                    vowels_map[word[r]]++;
                }
                r++;
            }
        }

        return ans;
    }

    long long  countOfSubstrings(string word, int k) {
        return countAtLeastMConsonants(word, k) - countAtLeastMConsonants(word, k + 1);
    }
};
