class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string, int> map;
        string temp = "";

        // Process the first sentence
        for (auto it : s1) {
            if (it == ' ') {
                if (!temp.empty()) {
                    map[temp]++;
                    temp = "";
                }
            } else {
                temp += it;
            }
        }
        if (!temp.empty()) {
            map[temp]++;
        }

        temp = "";

        // Process the second sentence
        for (auto it : s2) {
            if (it == ' ') {
                if (!temp.empty()) {
                    map[temp]++;
                    temp = "";
                }
            } else {
                temp += it;
            }
        }
        if (!temp.empty()) {
            map[temp]++;
        }

        vector<string> ans;
        for (auto it : map) {
            if (it.second == 1) {
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};
