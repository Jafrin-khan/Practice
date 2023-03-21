class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int src) {
   
        vector<vector<pair<int,int>>> adj(n+1);
        
        for(auto it : times){
            int node = it[0];
            int adjNode = it[1];
            int wt = it[2];
            
            adj[node].push_back({adjNode,wt});
        }
        
        priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>>> pq;//<node,time>
        pq.push({src,0});
        
        vector<int> disArr(n+1 , 1e9);
        disArr[src] = 0;
        int ans = -1;
        
        while(!pq.empty()){
            int node = pq.top().first;
            int timeTillNode = pq.top().second;pq.pop();
            
            for(auto it : adj[node]){
                int adjNode = it.first;
                int wt = it.second;
                if(disArr[adjNode] > wt + timeTillNode){
                    disArr[adjNode] = wt + timeTillNode;
                    pq.push({adjNode , wt + timeTillNode});
                    ans = wt + timeTillNode;
                }
            }
        }
        
        for(int i = 1 ; i <= n ; i++){
            if(disArr[i] == 1e9) return -1;
        }
        
         for(int i = 1 ; i <= n ; i++){
            ans = max(ans , disArr[i]);
         }
        return ans;
    }
};