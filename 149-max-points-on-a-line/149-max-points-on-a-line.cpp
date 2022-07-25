class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        
        
        int n = points.size();
        int ans = 1;
        for(int i = 0 ; i < n-1 ; i++){
            unordered_map<double,int> mp;
            for(int j = i + 1 ; j < n ; j++){
                
                double slope = (double)(points[j][1] - points[i][1])/(double)(points[j][0] - points[i][0]);
                if(slope==(-1/double(0)))slope=(1/double(0));
                mp[slope]++;
            }
            
            for(auto x : mp){
                ans = max(ans , x.second+1);
            }
            
        }
        
        return ans;
        
    }
};