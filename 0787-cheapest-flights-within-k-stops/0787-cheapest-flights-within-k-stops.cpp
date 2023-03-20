class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        
        vector<pair<int,int>> adj[n];
        
        for(auto it : flights){
            adj[it[0]].push_back({it[1],it[2]});
        }
        queue<pair<int,pair<int,int>>> q;
        q.push({src , {0 , 0}}); // <node,steps,cost>
        
        vector<int> disArr(n , 1e9);
        disArr[src] = 0;
        
        while(!q.empty()){
            auto front = q.front();q.pop();
            
            int node = front.first;
            int steps = front.second.first;
            int costTillNode = front.second.second;
            
            if(steps > k) continue;
            
            for(auto it : adj[node]){
                int adjNode = it.first;
                int adjW = it.second;
                
                if(steps <= k && adjW + costTillNode < disArr[adjNode]){
                    disArr[adjNode] = adjW + costTillNode;
                    q.push({adjNode,{steps+1,adjW + costTillNode}});
                }
                
            }
        }
         if(disArr[dst] == 1e9) return -1;
        return disArr[dst];
        
    }
};