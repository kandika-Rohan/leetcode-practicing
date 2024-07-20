class LRUCache {
public:
    class node{
        public:
        int key;
        int value;
        node*next;
        node*prev;
        node(int key,int value){
            this->key=key;
            this->value=value;
        }
    };
    int cap;
    unordered_map<int,node*>mpp;
    node*head=new node(-1,-1);
    node*tail=new node(-1,-1);
    LRUCache(int capacity) {
        cap=capacity;
        head->next=tail;
        tail->prev=head;
    }
    void addnode(node*newnode){
        node*temp=head->next;
        newnode->next=temp;
        newnode->prev=head;
        head->next=newnode;
        temp->prev=newnode;
    }
    void deletenode(node*delnode){
        node*delprev=delnode->prev;
        node*delnext=delnode->next;
        delprev->next=delnext;
        delnext->prev = delprev;
    }
    int get(int key) {
        if(mpp.find(key) != mpp.end()){
            //found
            node*resnode=mpp[key];
            int res=resnode->value;

            mpp.erase(key);
            deletenode(resnode);
            addnode(resnode);
            mpp[key]=resnode;
            return res;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(mpp.find(key) != mpp.end()){
            node*exisisting=mpp[key];
            mpp.erase(key);
            deletenode(exisisting);
        }
        if(mpp.size()==cap){
            mpp.erase(tail->prev->key);
            deletenode(tail->prev);
        }
        addnode(new node(key,value));
        mpp[key]=head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */