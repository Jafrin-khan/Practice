class MyStack {
public:
    /*
    queue<int> q1;
    queue<int> q2;
    
    MyStack() {
        
    }
    
    void push(int x) {
        q1.push(x);
    }
    
    int pop() {
        while(q1.size() > 1){
            q2.push(q1.front()); q1.pop();
        }
        
        int ans = q1.front();
        q1.pop();
        
        while(!q2.empty()){
            q1.push(q2.front());
            q2.pop();
        }
        
        return ans;
    }
    
    int top() {
        while(q1.size() > 1){
            q2.push(q1.front()); q1.pop();
        }
        
        int ans = q1.front();
        q2.push(ans);
        q1.pop();
        
        while(!q2.empty()){
            q1.push(q2.front());
            q2.pop();
        }
        
        return ans;
        
    }
    
    bool empty() {
        return q1.size() == 0;
    }
    */
    
    
    //APPROACH 2 IS BY USING A SINGLE QUEUE
    queue<int> q;
    
    MyStack() {
        
    }
    
    void push(int x) {
        q.push(x);
    }
    
    int pop() {
       if(q.size() == 0) return -1;
       int size = q.size()-1;
        
       while(size--){
           q.push(q.front());q.pop();
       }
        
       int ans = q.front();
        q.pop();
        
        return ans;
    }
    
    int top() {
       if(q.size() == 0) return -1;
       int size = q.size()-1;
        
       while(size--){
           q.push(q.front());q.pop();
       }
        
       int ans = q.front();
        q.pop();
        
        q.push(ans);
        
        return ans;
    }
    
    bool empty() {
        return q.size() == 0;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */