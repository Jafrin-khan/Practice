class Solution {
public:
    
    /*
    
    https://www.youtube.com/watch?v=Z2x-zalsebs
    
    */
    string pushDominoes(string s) {
        
        int n = s.size();
        vector<int> forces(n , 0);
        int force = 0;
        
        //parsing left to write
        for(int i = 0 ; i < n ; i++){
            if(s[i] == 'L') force = 0;
            else if(s[i] =='R') force = n;
            else force = max(force-1 , 0);
            
            forces[i] += force;
        }
        
        //parsing right to left
        force = 0;
        for(int i = n-1 ; i >= 0 ; i--){
            if(s[i] == 'R') force = 0;
            else if(s[i] =='L') force = n;
            else force = max(force-1 , 0); 
            
            forces[i] -= force;
        }
        
        string ans = "";
        for(auto it : forces){
            if(it < 0) ans+="L";
            else if(it > 0) ans+="R";
            else ans+=".";
        }
        
        return ans;
        
    }
};