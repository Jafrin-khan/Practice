class Solution {
public:
    
    int cal(vector<int>& p1, vector<int>& p2){
        
        int x = p2[0] - p1[0];
        int y = p2[1] - p1[1];
        
        return x*x + y*y;
    }
    
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        
        map<int,int> mp;
        
        mp[cal(p1 , p2)]++;
        mp[cal(p2 , p3)]++;
        mp[cal(p3 , p4)]++;
        mp[cal(p4 , p1)]++;
        mp[cal(p1 , p3)]++;
        mp[cal(p2 , p4)]++;
        
        if(mp.size() != 2){
            return false;
        }
        
        for(auto x : mp){
            return  x.second == 4;
        }
        
        return false;
        
    }
};