class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        
        int g = 0;
        int c = 0;
        
        for(int  i = 0 ; i < gas.size() ; i++){
            
            g += gas[i];
            c += cost[i];
        }
        
        if(c > g){
            return -1;
        }
        
        int ind = 0;
        int tank = 0;
        for(int i = 0 ; i < gas.size() ; i++){
            
            tank += gas[i] - cost[i];
            
            if(tank < 0){
                ind = i + 1;
                tank = 0;
            }
            
        }
        
        return ind;
        
    }
};