class Solution {
public:
    //By toposort we detect whether cycle is present or not...it can also be implemented via dfs
    
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        
         vector<int> adj[n];
        
        for(int i = 0 ; i < prerequisites.size() ; i++){
            int u = prerequisites[i][0];
            int v = prerequisites[i][1];
            adj[v].push_back(u);
        }
        
        vector<int> indegree(n,0);
        
        for(int i = 0 ; i < n ; i++){
            for(auto it : adj[i]) indegree[it]++;
        }
        
        int cnt = 0;
        queue<int> q;
        
        for(int i = 0 ; i < n ; i++){
            if(indegree[i] == 0){
                q.push(i);
            } 
        }
        
        while(!q.empty()){
            int node = q.front();q.pop();
            cnt++;
            
            for(auto it : adj[node]){
                indegree[it]--;
                if(indegree[it] == 0) {
                    q.push(it);
                }
            }
        }
        
        return cnt == n;
        
    }
};