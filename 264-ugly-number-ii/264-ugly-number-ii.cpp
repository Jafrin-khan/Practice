class Solution {
public:
    
    void f(long int i , set<long int>& st){
        
        if(i > INT_MAX){
            return;
        }
        
        if(st.find(i) != st.end()){
            return;
        }
        st.insert(i);
        
        f(i*2 , st);
        f(i*3 , st);
        f(i*5 , st);
    
        
    }
    int nthUglyNumber(int n) {
        
        set<long int> st;
        f(1 , st);
        
        int i = 0;
        int ans;
        
        for(auto x : st){
            if(++i == n){
                return x;
            }

        }
        return i;
    }
};