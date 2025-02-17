class Solution {
public:
    int backtrack(unordered_map<char, int>& freq) {
        int cnt = 0;
        for (auto& [ch, count] : freq) {
            if (count > 0) {
                cnt++; 
                freq[ch]--;  
                cnt += backtrack(freq); 
                freq[ch]++; 
            }
        }
        return cnt;
    }

    int numTilePossibilities(string tiles) {
        unordered_map<char, int> freq;
        for (char c : tiles) freq[c]++; 

        return backtrack(freq);
    }
};
