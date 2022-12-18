class Solution {
public:
    
    /*
    Time Complexity: O(V+E)+O(V), where V = no. of nodes and E = no. of edges. There can be at most V components. So, another O(V) time complexity.

Space Complexity: O(3N) + O(N) ~ O(3N): O(3N) for three arrays required during dfs calls and O(N) for recursive stack space.
    */
    
    /*
    TC = O(V + E) + O(V)
    SC = O(3N) + O(N) ~ O(3N)
    */
    
      bool dfs(int node,vector<int> &vis,vector<int> &pathVis,vector<vector<int>>& graph){
        vis[node]=1;
        pathVis[node]=1;
        //neighbours
        for(auto it:graph[node]){
            if(vis[it]==0){
                if(dfs(it,vis,pathVis,graph)==true)
                    return true;
            }
            else if(pathVis[it]==1)
                return true;
        }
        pathVis[node]=0;
        return false;
    }
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> pathVis(n,0);
        vector<int> vis(n,0);
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(vis[i]==0 ){
                if(dfs(i,vis,pathVis,graph)==true)
                    continue;
            }
            if(pathVis[i]==0)
                ans.push_back(i);
        }
        
        return ans;
        
    }
};