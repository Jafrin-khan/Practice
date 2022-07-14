class MinStack {
public:
    
    stack<int> st;
    stack<int> helper;
    
    MinStack() {
        
    }
    
    void push(int val) {
        st.push(val);
        
        if(helper.empty() || helper.top() >= val){
            helper.push(val);
        }
    }
    
    void pop() {
        
        if(st.empty()){
            return;
        }
        int top = st.top();
        st.pop();
        
        if(!helper.empty() && top == helper.top()){
            helper.pop();
        }
    }
    
    int top() {
        if(st.empty()){
            return -1;
        }
        return st.top();
    }
    
    int getMin() {
        if(helper.empty()){
            return -1;
        }
        return helper.top();
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