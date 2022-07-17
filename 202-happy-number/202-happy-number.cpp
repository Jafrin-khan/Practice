class Solution {
public:
    
    int f(int num){
        
        int ans = 0;
        while(num != 0){
            ans += (num%10 )* (num%10);
            num/=10;
        }
        
        return ans;
       
    }
    bool isHappy(int n) {
        
        unordered_map<int,int> mp;
        
        while(mp.find(n) == mp.end()){
            
            int elem = f(n);
            mp[n] = elem;
            n = elem;
            
            if(n == 1){
                return true;
            }
        }
       
        return false;
    }
};