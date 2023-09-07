class MinStack {
public:
// stack to keep integer and minimum value at level of stack
// This will make sure we have "Minimum at all instance of stack and even if we pop a few numbers, we can tell what was the minimum at that time.."
stack<pair<int,int>> s;
MinStack() {
}
// push the number twice for an empty stack otherwise push the minimum of (min till now and this num).
void push(int val) {
if(s.empty()){
s.push({val, val});
}
else{
int mini = min(s.top().second, val);
s.push({val, mini});
}
}
void pop() {
s.pop();
}
int top() {
return s.top().first;
}
int getMin() {
return s.top().second;
}
};
​
/**
* Your MinStack object will be instantiated and called as such:
* MinStack* obj = new MinStack();
* obj->push(val);
* obj->pop();
* int param_3 = obj->top();
* int param_4 = obj->getMin();
*/