class Solution {
public:
    
    void store(long int i , set<long int>& st){
        
        if(i >= INT_MAX){
            return;
        }
        
        if(st.find(i) != st.end()){
            return;
        }
         
        st.insert(i);
        
        store(i*2 , st);
        store(i*3 , st);
        store(i*5 , st);
    
    }
    int nthUglyNumber(int n) {
        
        set<long int> st;
        
        store(1 , st);
        int i = 0;
        
        for(auto x : st){
            
            if(++i == n){
                return x;
            }
            
            
        }
        
        return -1;
        
    }
};