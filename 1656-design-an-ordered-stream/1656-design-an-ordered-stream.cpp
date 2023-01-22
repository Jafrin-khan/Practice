class OrderedStream {
public:
    
    int ptr = 1;
    vector<string> v;
    
    OrderedStream(int n) {
        v.resize(n+1);
    }
    
    vector<string> insert(int idKey, string value) {
        vector<string> toReturn;
        
        v[idKey] = value;
        
        while(ptr < v.size() && !v[ptr].empty()){
            toReturn.push_back(v[ptr++]);   
        }
        
        return toReturn;
    }
};

/**
 * Your OrderedStream object will be instantiated and called as such:
 * OrderedStream* obj = new OrderedStream(n);
 * vector<string> param_1 = obj->insert(idKey,value);
 */