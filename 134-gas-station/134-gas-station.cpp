class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        
        int totCost = 0;
        int totPet = 0;
        
        int n = gas.size();
        
        for(int i = 0 ; i < n ; i++){
            totCost += cost[i];
            totPet += gas[i];
        }
        
        if(totCost > totPet){
            return -1;
        }
        
        int start = 0;
        int tank = 0;
        
  
        for(int i = 0 ; i < n ; i++){
            
            
            tank += gas[i] - cost[i];
            
            if(tank < 0){
                start = i+1;
                tank = 0;
            }
        
        }
        
        return start;
        
    }
};