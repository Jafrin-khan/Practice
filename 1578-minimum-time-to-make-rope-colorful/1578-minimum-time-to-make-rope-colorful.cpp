class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        
        int i = 0;
        int cost = 0;
        
        while(i < colors.size()){
            
            int j = i;
            int maxInd = i;
            while(j < colors.size() && colors[i] == colors[j]){
                if(neededTime[j] > neededTime[maxInd]){
                    maxInd = j;
                }
               j++; 
                
            }
            
           for(int k = i ; k < j ; k++){
               if(k != maxInd){
                   cost += neededTime[k];
               }
           }
            
           i = j;
        }
        
        return cost;
        
    }
};