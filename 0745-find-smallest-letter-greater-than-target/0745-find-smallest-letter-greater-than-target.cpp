class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        
        int l=0;
        int r=letters.size()-1;
        char ch=' ';
        while(l<=r){
            int mid=(l+r)/2;
            if(letters[mid]>target){
                ch=letters[mid];
                r=mid-1;
            }
            else{
               l=mid+1;
            }
        }

        return ch == ' '?letters[0]:ch;
    }
};