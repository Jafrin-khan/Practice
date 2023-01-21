class Solution {
public:
    
    //two pointers
    
    /*
    TC = O(NlogN)
    SC = O(1)
    */
    
    int numRescueBoats(vector<int>& people, int limit) {
        
        sort(people.begin() , people.end());
        int light = 0;
        int heavy = people.size()-1;
        
        int boats = 0;
        
        while(light <= heavy){
            
            boats++;
            if(people[light] + people[heavy] <= limit){
               light++;
            }
            heavy--;
        }
        
        return boats;
    }
};