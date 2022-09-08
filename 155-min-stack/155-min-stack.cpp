class MinStack {
public:
    
    stack<int> st;
    stack<int> h;
    
    MinStack() {
        
    }
    
    void push(int val) {
        st.push(val);
        
        
          if(h.empty() || h.top() >= val){
            h.push(val);
        }
        
    }
    
    void pop() {
        
        if(st.empty()){
            return;
        }
        
        if(st.top() == h.top()){
            h.pop();
        }
        st.pop();
        
        
    }
    
    int top() {
        
        if(st.empty()){
            return -1;
        }
        return st.top();
        
    }
    
    int getMin() {
        
        if(h.empty()){
            return -1;
        }
        return h.top();
        
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */