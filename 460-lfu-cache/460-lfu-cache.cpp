
 struct Node{
        int key , value , cnt;
        Node* next;
        Node* prev;
        
        Node(int _key , int _value){
            key = _key;
            value = _value;
            cnt = 1;
        }
    };
    
    struct List{
        
        int size;
        Node* head;
        Node* tail;
        
        List(){
            head = new Node(0 , 0);
            tail = new Node(0 , 0);
            head->next = tail;
            tail->prev = head;
            size = 0;
        }
        
    void addFront(Node *node) {
        Node* temp = head->next;
        node->next = temp;
        node->prev = head;
        head->next = node;
        temp->prev = node;
        size++; 
    }
    
    void removeNode(Node* delnode) {
        Node* delprev = delnode->prev;
        Node* delnext = delnode->next;
        delprev->next = delnext;
        delnext->prev = delprev;
        size--; 
    }
        
    };
    
class LFUCache {
public:
    
    //lru jaise
    map<int, Node*> keyNode;
    
    //int --> freq and List-->individual list of each frequency
    map<int, List*> freqListMap;
    int maxSizeCache;
    int minFreq;
    int curSize;
    
    LFUCache(int capacity) {
        maxSizeCache = capacity;
        minFreq = 0;
        curSize = 0;
    }
    
    
    void updateFreqListMap(Node *node){
        
        keyNode.erase(node->key);
        //from where we get cnt find out
        freqListMap[node->cnt]->removeNode(node);
        
        if(node->cnt == minFreq && freqListMap[node->cnt]->size == 0){
            //this means out list becomes empty as no element is there hence minFreq will be of next list hence increase minfreq
            minFreq++;
        }
        
        List* nextHigherFreqList = new List();
        
        if(freqListMap.find(node->cnt + 1) != freqListMap.end()){
          //agr minFreq waali list pehle se present h to us list ko nyi waali list se equate
            nextHigherFreqList = freqListMap[node->cnt + 1];
        }
        
        node->cnt += 1;
        nextHigherFreqList->addFront(node);
        //mapping freq with list
        freqListMap[node->cnt] = nextHigherFreqList;
        keyNode[node->key] = node;
        
    }
    
    int get(int key) {
        
        if(keyNode.find(key) != keyNode.end()){
            Node* node = keyNode[key];
            int val = node->value;
            updateFreqListMap(node);
            return val;
        }
        
        return -1;
    }
    
    void put(int key, int value) {
        
        //a check if max size of cache is zero then we cant put anything to it hence simply return
        if(maxSizeCache == 0){
            return;
        }
        
        //node to be put is already present the we just have to update its value and freq
        if(keyNode.find(key) != keyNode.end()){
            Node* node = keyNode[key];
            node->value = value;
            updateFreqListMap(node);
        }
        
        else{
            
            if(curSize == maxSizeCache){
                //minFreq waale element ko remove kr denge
                List* list = freqListMap[minFreq];
                keyNode.erase(list->tail->prev->key);//LRU waala node remove kra idhr
                freqListMap[minFreq]->removeNode(list->tail->prev);
                curSize--;
            }
            
            //adding new node hence size increases....pehle exist nhi krta tha isliye minfreq is 1
            curSize++;
            minFreq = 1;
            List* listFreq = new List();
            
            if(freqListMap.find(minFreq) != freqListMap.end()){
                //agr 1 minFreq waali list pehle se present h to us list ko nyi waali list se equate
                listFreq = freqListMap[minFreq];
            }
            
            Node* node = new Node(key , value);
            listFreq->addFront(node);
            keyNode[key] = node;
            freqListMap[minFreq] = listFreq;
            
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */