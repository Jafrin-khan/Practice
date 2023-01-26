
class BrowserHistory {
public:
   
    vector<string> history;
    int idx = 0;
public:
    //O(1)
    BrowserHistory(string homepage) {
        history.push_back(homepage);
        idx = 1;
    }
    
    //O(1)
    void visit(string url) {
        while (history.size() > idx)
            history.pop_back();
        history.push_back(url);
        idx++;
    }
    
    //O(1)
    string back(int steps) {
        idx = max(1, idx - steps);
        return history[idx-1];
    }
    
    //O(1)
    string forward(int steps) {
        idx = min(int(history.size()), idx + steps);
        return history[idx-1];
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */