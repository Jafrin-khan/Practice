class FreqStack {
public:
    /*
    TC = O(N)
    SC = O(N)
    */
    unordered_map<int,int> mp;
    priority_queue<vector<int>> pq;
    int time = 0;//time is used since we have to give most recent ele whose fre is greatest ....stack wala logic(most recent ele return krna h)
    FreqStack() {
        
    }
    //O(1)*O(N)...for N numbers
    void push(int val) {
        mp[val]++;
        pq.push({mp[val],time,val});
        time++;
    }
    
    //O(1)
    int pop() {
        auto top = pq.top();
        pq.pop();
        int ans = top[2];
        mp[ans]--;
        
        return ans;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */