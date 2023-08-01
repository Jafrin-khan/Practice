class MinStack {
public:
    
    /*
    TC = O(1)*O(N)...for all the elements
    SC = O(N)
    */
    
    map<int,int> mp;
    stack<int> st;
    MinStack() {
        
    }
    //O(1)
    void push(int val) {
        st.push(val);
        mp[val]++;
    }
    
    //O(1)
    void pop() {
        int val = st.top();
        st.pop();
        if(--mp[val] == 0)mp.erase(val);
    }
    //O(1)
    int top() {
        return st.top();
    }
    //O(1)
    int getMin() {
          return mp.begin()->first ;////////////
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