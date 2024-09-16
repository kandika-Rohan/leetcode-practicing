class Trie {
    struct trieNode{
        bool isendswith;
        trieNode* children[26];
    };
    trieNode*getNode(){
        trieNode*newNode=new trieNode();
        newNode->isendswith=false;
        for(int i=0;i<26;i++){
            newNode->children[i]=nullptr;
        }
        return newNode;
    }
public:
    trieNode*root;
    Trie() {
        root=getNode();
    }
    
    void insert(string word) {
        trieNode*crawler=root;

        for(auto it:word){
            int index=it-'a';
            if(crawler->children[index] == nullptr){
                crawler->children[index]=getNode();
            }
            crawler=crawler->children[index];
        }
        crawler->isendswith=true;
    }
    
    bool search(string word) {

        trieNode*crawler=root;

        for(auto it:word){
            int index=it-'a';
            if(crawler->children[index] == nullptr){
                return false;
            }
            crawler=crawler->children[index];
        }

        if(crawler->isendswith == true){
            return true;
        }
        return false;
    }
    
    bool startsWith(string word) {

         trieNode*crawler=root;
         int i=0;
        for(auto it:word){
            int index=it-'a';
            if(crawler->children[index] == nullptr){
                return false;
            }
            i++;
            crawler=crawler->children[index];
        }

        if(i == word.size()){
            return true;
        }
        return false;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */