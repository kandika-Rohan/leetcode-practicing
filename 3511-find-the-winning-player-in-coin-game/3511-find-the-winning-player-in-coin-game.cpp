class Solution {
public:
    string losingPlayer(int x, int y) {
    int total_turns = min(x, y / 4);
    if (total_turns % 2 == 1) {
        return "Alice";
    } else {
        return "Bob";
    }
    }
};