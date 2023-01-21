class Solution {
public:
    
    /*
    https://www.youtube.com/watch?v=VD9NACqBCw4
    
    TC = O(6*N) ~ O(N)
    */
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        
        int dice = 1;
        int i = 0;
      
        while(i < tops.size()){
            
            if(tops[i] == dice || bottoms[i] == dice){
                i++;
            }
            
            else{
                dice++;
                if(dice > 6){
                    return -1;
                }
                i = 0;
            }
        }
        
        int ans1 = 0;
        
        for(int i = 0 ; i < tops.size() ; i++){
            if(tops[i] != dice){
                ans1++;
            }
        }
       
        int ans2 = 0;
      
        for(int i = 0 ; i < bottoms.size() ; i++){
            if(bottoms[i] != dice){
                ans2++;
            }
        }
        
        return min(ans1,ans2);
    }
};