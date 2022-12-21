class Solution {
public:
    
      
    /*
    we can use DFS but here i have used kahn's algo for cycle ddetection
    TC = O(V+E)
    SC = O(2N)
    */
    
      vector<int> isCyclic(int v, vector<int> adj[]) {
        
        vector<int> indegree(v , 0);
        
        for(int i = 0 ; i < v ; i++){
            
            for(auto it : adj[i]){
                indegree[it]++;
            }
        }
        
        queue<int> q;
        vector<int> topoSort;
        for(int i = 0 ; i < v ; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        
        int cnt = 0;
        while(!q.empty()){
            
            int node = q.front();
            q.pop();
            topoSort.push_back(node);
            
            for(auto it : adj[node]){
                indegree[it]--;
                
                if(indegree[it] == 0){
                    q.push(it);
                }
            }
            
        }
        
        return topoSort;
    }
  
    vector<int> findOrder(int n, vector<vector<int>>& prerequisites) {
        
         vector<int> adj[n];
        
        for(int i = 0 ; i < prerequisites.size() ; i++){
                int u = prerequisites[i][0];
                int v = prerequisites[i][1];
                
                //bs yhan change h baaki same hi hai Course Schedule I ke
                adj[v].push_back(u);
                
            
        }
        
        vector<int> ans = isCyclic(n, adj); 
        
        if(ans.size() != n){
            return {};
        }
        
        return ans;
        
    }
};