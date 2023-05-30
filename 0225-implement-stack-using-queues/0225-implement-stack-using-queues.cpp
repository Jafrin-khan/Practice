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
      //sirf issi code se humne apni queue ko stack ki tarah use kr lena hai
      int s = q.size();
      q.push(x);
      for (int i = 0; i < s; i++) {

        q.push(q.front());
        q.pop();
      }
    }
    
    int pop() {
        int n = q.front();
        q.pop();
        return n;
    }
    
    int top() {
     return q.front();
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