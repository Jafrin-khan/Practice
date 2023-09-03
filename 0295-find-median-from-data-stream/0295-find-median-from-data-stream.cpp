class MedianFinder {
public:
    
    priority_queue<int> mx;
    priority_queue<int , vector<int> , greater<int>> mn;
    
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        mx.push(num);
        mn.push(mx.top());mx.pop();
        
        if(mn.size() > mx.size()){
            mx.push(mn.top());
            mn.pop();
        }
    }
    
    double findMedian() {
        int n = mx.size();
        int m = mn.size();
        
        if((n+m)%2) return mx.top();
        else return (double)(mn.top() + mx.top())/2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */