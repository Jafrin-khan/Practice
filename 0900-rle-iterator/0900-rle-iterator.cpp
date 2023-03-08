class RLEIterator {
public:
  int i;
  vector<int> v;
    
    RLEIterator(vector<int>& A) {
        v = A;
        i = 0;
    }
    
    int next(int n) {
        while (i < v.size()){
            if (v[i]>=n){
                v[i]-=n;
                return v[i+1];
            }else{
                n -= v[i];//ye condition ni daali thi pichle submissions mai
                i += 2;
            }
        }
        return -1;
    }
};

/**
 * Your RLEIterator object will be instantiated and called as such:
 * RLEIterator* obj = new RLEIterator(encoding);
 * int param_1 = obj->next(n);
 */