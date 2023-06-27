class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        
        vector<vector<int>> adj[n];
        
        for(auto it : flights){
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            
            adj[u].push_back({v,wt});
        }
        
        queue<pair<int,pair<int,int>>> q;
        q.push({0,{src,0}});//<stops,<city,dis>>
        
        vector<int> disArr(n , 1e9);
        disArr[src] = 0;
       
        while(!q.empty()){
            int stops = q.front().first;
            int city = q.front().second.first;
            int wt = q.front().second.second;q.pop();
            
            if(stops > k) continue;
            
            for(auto it : adj[city]){
                if(it[1] + wt < disArr[it[0]] && stops <= k){
                    disArr[it[0]] = it[1] + wt;
                    q.push({stops+1,{it[0] , it[1] + wt}});
                }
            }
        }
        
       if(disArr[dst] == 1e9) return -1;
        return disArr[dst];
            
    }
};