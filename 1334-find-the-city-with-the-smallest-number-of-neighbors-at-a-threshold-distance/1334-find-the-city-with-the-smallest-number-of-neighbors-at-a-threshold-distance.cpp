class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        
        vector<vector<int>> disMatrix(n , vector<int>(n , 1e9));
        
        //yhn adjacency matrix bnaare lekin usse disMatrix naam dere kyunki min dis nikaalna h to samajhne m easy
        for(auto it : edges){
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            
            disMatrix[u][v] = wt;
            disMatrix[v][u] = wt;
        }
        
        //diagonal elements zero hi hoteyy hai
        for(int i = 0 ; i < n ; i++) disMatrix[i][i] = 0;
        
        //simple Floyd wrshall algo to fill disMatrix with shortest distances
        for(int k = 0 ; k < n ; k++){
            for(int i = 0 ; i < n ; i++){
                for(int j = 0 ; j < n ; j++){
                        disMatrix[i][j] = min(disMatrix[i][j] , disMatrix[i][k] + disMatrix[k][j]);
                    }
                }
            }
        
        
        //cntCity is max possible initially while cityNum is not known to us hence -1
        int cntCity = n;
        int cityNum = -1;
        
       // again iterating in disMatrix aur hum wo city dhundre jiske neighbours ka distance distanceThreshold se kam hai....fir iske cnt ko maxCnt yaani cntCity se compare krke hum min cnt maintain krre hai aur corresponding city ki value store krte jaare h
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