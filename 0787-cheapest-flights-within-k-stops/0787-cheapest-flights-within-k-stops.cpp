class Solution {
public:
    //TC and SC pichle submission m
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        
        vector<pair<int,int>> adj[n];
        
        for(auto it : flights){
            adj[it[0]].push_back({it[1],it[2]});
        }
        
        vector<int> disArr(n,1e9);
        disArr[src] = 0;
        
        queue<pair<int,pair<int,int>>> q;// <stops , node , dist>
        q.push({0 ,{ src , 0}});
        
        while(!q.empty()){
            auto front = q.front();q.pop();
            int stops = front.first;
            int node = front.second.first;
            int cost = front.second.second;
            
            if(stops > k) continue;
            
            for(auto it : adj[node]){
                int adjNode = it.first;
                int edW = it.second;
                
                if(stops <= k && cost + edW < disArr[adjNode]){
                    disArr[adjNode] = cost + edW;
                    q.push({stops+1,{adjNode,cost+edW}});
                }
                
            }
            
        }
        
        if(disArr[dst] == 1e9) return -1;
        
        return disArr[dst];
        
    }
};