class Solution {
public:
    char kthCharacter(int k) {
        string original="a";

        while(original.size()<=k){
            string s="";
            for(int i=0;i<original.size();i++){
                int val=original[i]-'a'+1;
                cout<<val+'a'<<" ";
                s+=(val+'a');
            }
            original=original+s;
        }
        cout<<original<<endl;
        return original[k-1];
    }
};