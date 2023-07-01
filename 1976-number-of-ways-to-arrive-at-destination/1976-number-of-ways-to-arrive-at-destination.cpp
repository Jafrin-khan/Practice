class Solution {
public:
    
      int mod=1e9+7;
    
    int countPaths(int n, vector<vector<int>>& roads) {
         int mod=1e9+7;
        vector<vector<pair<long long,long long>>>adj(n);
        
        for(auto road : roads){
            adj[road[0]].push_back({road[1],road[2]});
            adj[road[1]].push_back({road[0],road[2]});
        }
       
        priority_queue<pair<long long,long long>, vector<pair<long long,long long>>, greater<pair<long long,long long>>> pq;//<dis,node>
        vector<long long int>disArr(n,1e15);
        vector<long long>ways(n,0);
        ways[0]=1;
        disArr[0]=0;
        pq.push({0,0});
        while(pq.empty()==false){
            
            auto x=pq.top();
            long long cost=x.first;
            long long node=x.second;pq.pop();
            
            for(auto it:adj[node]){
                long long adjNode=it.first; 
                long long wt=it.second;
                
                if(wt+cost<disArr[adjNode]){
                    disArr[adjNode]=(wt+cost);
                    pq.push({wt+cost,adjNode});
                    ways[adjNode]=ways[node];
                }
                else if((wt+cost)==disArr[adjNode]){
                    ways[adjNode]=(ways[adjNode]+ways[node])%mod;
                }
                
            }
        }
        return ways[n-1];
    }
};