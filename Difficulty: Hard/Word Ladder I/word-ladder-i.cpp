//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int wordLadderLength(string startWord, string targetWord, vector<string>& words) {
        // Code here
        queue<pair<string,int>>q;
        unordered_set<string>st(words.begin(),words.end());
        q.push({startWord,1});
        st.erase(startWord);
        
        while(!q.empty()){
            string word=q.front().first;
            int count=q.front().second;
            q.pop();
            if(word==targetWord){
                return count;
            }
            for(int i=0;i<word.size();i++){
                char original=word[i];
                for(char ch='a';ch <= 'z' ; ch++){
                    word[i]=ch;
                    if(st.find(word) != st.end()){
                        q.push({word,count+1});
                        st.erase(word);
                    }
                }
                word[i]=original;
            }
        }
        return 0;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<string>wordList(n);
		for(int i = 0; i < n; i++)cin >> wordList[i];
		string startWord, targetWord;
		cin >> startWord >> targetWord;
		Solution obj;
		int ans = obj.wordLadderLength(startWord, targetWord, wordList);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends