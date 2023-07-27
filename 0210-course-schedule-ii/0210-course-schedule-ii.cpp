class Solution {
public:
  
    vector<int> findOrder(int n, vector<vector<int>>& nums) {
        
        vector<vector<int>> adj(n);
        vector<int> indegree(adj.size() , 0);
        
        for(int i = 0 ; i < nums.size() ; i++){
            int u = nums[i][0];
            int v = nums[i][1];
            
            adj[v].push_back(u);
            indegree[u]++;
        }
        
       
        vector<int> topo;
        queue<int> q;
        
        for(int i = 0 ; i < indegree.size() ; i++){
                if(indegree[i] == 0) q.push(i);
        }
        
        while(!q.empty()){
            int node = q.front();q.pop();
            topo.push_back(node);
            
            for(auto it : adj[node]){
                indegree[it]--;
                if(indegree[it] == 0) q.push(it);
            }
        }
    
        if(topo.size() == n) return topo;
        
        return {};
        
    }
};