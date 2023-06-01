class LRUCache {
public:
    
    class Node{
        public:
        int key;
        int val;
        Node* next;////////
        Node* prev;///////
        Node(int key_ , int value_){
            key = key_;
            val = value_;
        }
    };
    
    unordered_map<int , Node*> mp;//<key,node>
    Node* head = new Node(-1,-1);
    Node* tail = new Node(-1,-1);
    int size;
    
    void addNode(Node* newNode){
        Node* temp = head->next;
        head->next = newNode;
        newNode->prev = head;
        newNode->next = temp;
        temp->prev = newNode;
    }
    
    void deleteNode(Node* node){
        Node* prevNode = node->prev;
        Node* nextNode = node->next;
        prevNode->next = nextNode;
        nextNode->prev = prevNode;

    }
    
    LRUCache(int capacity) {
        head->next = tail;
        tail->prev = head;
        size = capacity;
    }
    
    int get(int key) {
        if(mp.find(key) != mp.end()){
            Node* node = mp[key];
            int res = node->val;/////////////////////////
            mp.erase(key);
            deleteNode(node);
            addNode(node);
            mp[key] = head->next;///////////////////////////////
            return  res;
        }
        
        return -1;
    }
    
    void put(int key, int value) {
        
        if(mp.find(key) != mp.end()){//////////////
            Node* existingNode = mp[key];////////////////
            mp.erase(key);//////////////
            deleteNode(existingNode);//////////////
        }
        
    
        if(mp.size() == size){
            mp.erase(tail->prev->key);/////////////////
            deleteNode(tail->prev);
        }
            
        Node* node = new Node(key,value);
        addNode(node);
        mp[key] = head->next;///////////////
        
        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */