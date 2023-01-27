class RecentCounter {
public:
  
    queue<int> q;
    RecentCounter() {
        
    }
    int ping(int t) {
        int left = t - 3000;
        int right = t;
       
        while(!q.empty() && q.front() < left) {q.pop();}
        
        q.push(t);
        return q.size();
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */