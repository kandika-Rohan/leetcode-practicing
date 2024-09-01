class Solution {
public:
    bool checkTwoChessboards(string coordinate1, string coordinate2) {
        int ch1 = coordinate1[0] - 'a';
        int val1 = coordinate1[1] - '0';

        int ch2 = coordinate2[0] - 'a';
        int val2 = coordinate2[1] - '0';

       
        bool color1 = (ch1 + val1) % 2;
        bool color2 = (ch2 + val2) % 2;

        return color1 == color2;
    }
};
