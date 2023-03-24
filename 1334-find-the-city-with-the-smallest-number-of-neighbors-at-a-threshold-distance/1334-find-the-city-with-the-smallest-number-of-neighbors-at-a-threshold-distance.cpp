class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        
        vector<vector<int>> disMatrix(n , vector<int>(n , 1e9));
        
        for(auto it : edges){
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            
            disMatrix[u][v] = wt;
            disMatrix[v][u] = wt;
        }
        
        for(int i = 0 ; i < n ; i++) disMatrix[i][i] = 0;
        
        for(int k = 0 ; k < n ; k++){
            for(int i = 0 ; i < n ; i++){
                for(int j = 0 ; j < n ; j++){
                        disMatrix[i][j] = min(disMatrix[i][j] , disMatrix[i][k] + disMatrix[k][j]);
                    }
                }
            }
        
        
        int cntCity = n;
        int cityNum = -1;
        
        for(int i = 0 ; i < n ; i++){
            int cnt = 0;
            for(int j = 0 ; j < n ; j++){
                if(disMatrix[i][j] <= distanceThreshold){
                       cnt++;
                }
            }
            
            if(cnt <= cntCity){
                cntCity = cnt;
                cityNum = i;
            }
        }
        
        return cityNum;
    }
};