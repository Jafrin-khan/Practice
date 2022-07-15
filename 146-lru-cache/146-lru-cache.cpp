class LRUCache {
public:
    
    class node{
        public:
        int key;
        int val;
        node* next;
        node* prev;
        node(int key_ , int val_){
            key = key_;
            val = val_;
        }
    };
    
    node* head = new node(-1,-1);
    node* tail = new node(-1,-1);
    int cap;
    unordered_map<int,node*> mp;
    
    LRUCache(int capacity) {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }
    
    void addNode(node* newNode){
        node* temp = head->next;
        head->next = newNode;
        newNode->prev = head;
        newNode->next = temp;
        temp->prev = newNode;
    }
    
    void deleteNode(node* delNode){
        
        node* delPrev = delNode->prev;
        node* delNext = delNode->next;
        delPrev->next = delNext;
        delNext->prev = delPrev;
    
    }
    int get(int key_) {
        
       if(mp.find(key_) != mp.end()){
           node* resNode = mp[key_];
           int ans = resNode->val;
           mp.erase(key_);
           deleteNode(resNode);
           addNode(resNode);
           mp[key_] = head->next;
           return ans;
       }
        
        return -1;
    }
    
    void put(int key_, int value) {
        
        if(mp.find(key_) != mp.end()){
            node* existingNode = mp[key_];
            mp.erase(key_);
            deleteNode(existingNode);
        }
        
        if(mp.size() == cap){
            mp.erase(tail->prev->key);
            deleteNode(tail->prev);
        }
        
        addNode(new node(key_ , value));
        mp[key_] = head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */