class Solution {
public:
    
    /*
    TC = O(V + 2E)..... Where V = Vertices, 2E is for total degrees as we traverse all adjacent nodes.
    SC = O(3VO) ~ (V)....., Space for queue data structure, colour array and an adjacency list.
    */
    
    /*
    BFS
    */
    
    bool check(int start , vector<int>& color , vector<vector<int>>& adj){
        queue<int> q;
        
        q.push(start);
        color[start] = 0;
        
        while(!q.empty()){
            
            int node = q.front();
            q.pop();
            
            for(auto it : adj[node]){
                
                if(color[it] == -1){
                    color[it] = !color[node];
                    q.push(it);
                }
                
                else{
                    if(color[it] == color[node]){
                        return false;
                    }
                }
            }
        }
        
        return true;
        
    }
    bool isBipartite(vector<vector<int>>& adj) {
        
        vector<int> color(adj.size() , -1);
        //for loop for considering non connected components ,i.e, separate graphs as well
        for(int i = 0 ; i < adj.size() ; i++){
            
            if(color[i] == -1){
                if(!check(i , color , adj)){
                    return false;
                }
            }
        }
        
        return true;
       
    }
};