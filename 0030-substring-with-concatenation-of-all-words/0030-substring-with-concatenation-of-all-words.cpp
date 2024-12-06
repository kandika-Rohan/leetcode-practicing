class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        unordered_map<string, int> counts;
        for (string word : words) counts[word]++;

        int n = s.length();
        int num = words.size();
        int len = words[0].length();

        vector<int> indexes;
        // Traverse through each possible starting point within the first 'len' characters
        for (int i = 0; i < len; i++) {
            unordered_map<string, int> seen;
            int start = i, count = 0;

            for (int j = i; j <= n - len; j += len) {
                string word = s.substr(j, len);
                // Check if the word is valid (exists in counts)
                if (counts.find(word) != counts.end()) {
                    seen[word]++;
                    count++;

                    // If seen word exceeds the count, shift the window
                    while (seen[word] > counts[word]) {
                        string leftWord = s.substr(start, len);
                        seen[leftWord]--;
                        start += len;
                        count--;
                    }

                    // If all words matched, add the starting index
                    if (count == num) {
                        indexes.push_back(start);
                    }
                } else {
                    // Reset the window if an invalid word is encountered
                    seen.clear();
                    count = 0;
                    start = j + len;
                }
            }
        }
        return indexes;
    }
};