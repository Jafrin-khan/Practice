class MedianFinder {
public:
    
    priority_queue<int> mx;
    priority_queue<int , vector<int> , greater<int>> mn;
    
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        
        mx.push(num);
        mn.push(mx.top());
        mx.pop();
        
        if(mn.size() > mx.size()){
            mx.push(mn.top());
            mn.pop();
        }
        
    }
    
    double findMedian() {
        
        double ans;
        if((mn.size() + mx.size())%2){
            ans = mx.top();
        }
        
        else{
            ans = (mx.top() + mn.top());
            ans/=2;
        }
        
        return ans;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */