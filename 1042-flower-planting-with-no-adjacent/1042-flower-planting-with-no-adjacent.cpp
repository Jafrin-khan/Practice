class Solution {
public:
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        
    vector <int> adj[n+1];
    vector <int> color(n+1, 0); //color vector for 1 to n colors
    
    //create an adjancency list for bidirectional edges 
    for(auto x: paths){
        adj[x[0]].push_back(x[1]);
        adj[x[1]].push_back(x[0]);
    }
    
    for(int i=1;i<=n;i++){
        //if the vertex is not colored give it color 1 initially and push it in a queue
        if(color[i]==0){
            color[i]=1;
            queue <int> q;
            q.push(i);
            
            //search for all adjacents of popped node until the queue is empty
            
            while(!q.empty()){
                int node= q.front();
                q.pop();
                
                for(auto ad: adj[node]){
                    
                    // if the adjacent node is not colored then give it the current+1 color
                    // else if colored then change current color to current + 1 color
                    
                    if(color[ad]==0){
                        color[ad]= (color[node]+1);
                        q.push(ad);
                    }
                    else if(color[node] == color[ad]){
                        color[ad]= (color[node]+1);
                    }
                    
                    // if the value of color exceeds 4 i.e. there are more than 3 edges 
                    //change the value to 1
                    
                    if(color[ad]==5)
                        color[ad]=1;
                    
                }
            }
        }
    }
    
    //since color are 1 based indexing erase the 0th elem from color vector
    color.erase(color.begin());
    return color;
    }
};