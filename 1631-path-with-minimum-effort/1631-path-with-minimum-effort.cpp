class Solution {
public:
    
     /*
  TC = ElogV ----> O(n*m*4*log(n*m)).......{log(v) = log(n*m)}..priority_queue l liye h ye
  SC = O(n*m)
  */
    int minimumEffortPath(vector<vector<int>>& heights) {
        
         int n = heights.size();
        int m = heights[0].size();
        
        //{diff , {row,col}}
        priority_queue<pair<int , pair<int,int>> ,
        vector<pair<int , pair<int,int>>> ,
        greater<pair<int , pair<int,int>>>> pq;
        
        vector<vector<int>> dist(n , vector<int>(m , 1e9));
        
        dist[0][0] = 0;
        pq.push({0 , {0,0}});
        
        int dx[] = {-1 , 0 , +1 , 0};
        int dy[] = {0 , +1 , 0 , -1};
        
        while(!pq.empty()){
            
            auto it = pq.top();
            pq.pop();
            
            int diff = it.first;
            int r = it.second.first;
            int c = it.second.second;
            
            if(r == n-1 && c == m-1){
                return diff;
            }
            
            for(int i = 0 ; i < 4 ; i++){
                
                int nr = r + dx[i];
                int nc = c + dy[i];
                
                if(nr >= 0 && nc >= 0 && nr < n && nc < m){
                    
                    int newEffort = max(abs(heights[r][c] - heights[nr][nc]) , diff);
                    if(newEffort < dist[nr][nc]){
                        dist[nr][nc] = newEffort;
                        pq.push({newEffort , {nr , nc}});
                    }
                }
            }
            
            
        }
        
        
        return 0;
    }
};