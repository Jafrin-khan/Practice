class Solution {
public:
    int findCheapestPrice(int v, vector<vector<int>>& flights, int src, int dst, int k) {
        
        vector<vector<pair<int,int>>> adj(v);
        
        for(auto it : flights){
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            
            adj[u].push_back({v , wt});
        }
        
        int ans = 1e9;
        
        
        vector<int> dis(v , 1e9);
        // priority_queue<pair<pair<int,int>,int> , vector<pair<pair<int,int>,int>> , greater<pair<pair<int,int>,int>>> pq;//<{{cost,steps},node}
        
        queue<pair<pair<int,int> , int>> q;
        
        q.push({{0 , 0} , src});
        dis[src] = 0;
          
        while(!q.empty()){
            int cost = q.front().first.first;
            int steps = q.front().first.second;
            int node = q.front().second; q.pop();
            
            if(steps > k) continue;
            
            for(auto it : adj[node]){
                int adjNode = it.first;
                int wt = it.second;
                if(dis[adjNode] > cost + wt){
                    dis[adjNode] = cost + wt;
                    q.push({{dis[adjNode] , steps+1} , adjNode});
                }
            }
        }
        
        if(dis[dst] == 1e9) return -1;
        
        return dis[dst];
    }
};