class Solution {
public:
    
    bool isCycle(int node , vector<int>& vis , vector<int>& pathVis , vector<vector<int>>& adj){
        
        vis[node] = 1;
        pathVis[node] = 1;
        for(auto it : adj[node]){
            if(!vis[it]){
                if(isCycle(it , vis , pathVis , adj)) return true;
            }
            
            else if(pathVis[it]) return true;
        }
        
        pathVis[node] = 0;
        return false;
    }
    
    bool canFinish(int n, vector<vector<int>>& nums) {
        
        vector<vector<int>> adj(n);
        
        for(int i = 0 ; i < nums.size() ; i++){
            int u = nums[i][0];
            int v = nums[i][1];
            
            adj[u].push_back(v);
        }
        
        vector<int> vis(n , 0);
        vector<int> pathVis(n , 0);
        
        for(int i = 0 ; i < n ; i++){
            if(!vis[i]){
                if(isCycle(i , vis , pathVis , adj)) return false;
            }
        }
        
        return true;
    }
};