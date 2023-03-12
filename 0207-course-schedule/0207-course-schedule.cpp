class Solution {
public:
     bool isCycle(int node , vector<vector<int>>& adj , vector<int>& vis , vector<int>& dfsVis){
        vis[node] = 1;
        dfsVis[node] = 1;
        for(auto it : adj[node]){
            if(!vis[it]){
                if(isCycle(it , adj, vis , dfsVis)) return true;
            }
            else if(dfsVis[it] == 1) return true;
        }
        
        dfsVis[node] = 0;
        return false;
    }
  
    bool canFinish(int n, vector<vector<int>>& nums) {
      vector<vector<int>> adj(n);
       
       for(int i = 0 ; i < nums.size() ; i++){
           adj[nums[i][0]].push_back(nums[i][1]);// as directed graph
       }
        
       vector<int> vis(n,0);
       vector<int> dfsVis(n,0);
        
       for(int i = 0 ; i < n ; i++){
           if(!vis[i] && isCycle(i , adj , vis,dfsVis)) return false;
       }
        
        return true;
    }
};