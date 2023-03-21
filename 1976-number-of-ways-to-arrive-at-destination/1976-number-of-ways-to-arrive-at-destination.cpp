class Solution {
public:

    int countPaths(int n, vector<vector<int>>& r) {
        
      int mod=1e9+7;
        vector<vector<pair<long long,long long>>>adj(n);
        for(int i=0;i<r.size();i++){
            adj[r[i][0]].push_back({r[i][1],r[i][2]});
            adj[r[i][1]].push_back({r[i][0],r[i][2]});
        }
        vector<long long>c(n,0);
        c[0]=1;
        priority_queue<pair<long long,long long>, vector<pair<long long,long long>>, greater<pair<long long,long long>>> pq;
        vector<long long int>dist(n,1e15);
        dist[0]=0;
        pq.push({0,0});
        while(pq.empty()==false){
            auto x=pq.top();
            long long dis=x.first;
            long long node=x.second;
            pq.pop();
            for(auto it:adj[node]){
                long long wt=it.second;
                long long y=it.first; 
                if(wt+dis<dist[y]){
                    dist[y]=(wt+dis);
                    pq.push({dist[y],y});
                    c[y]=c[node];
                }
                else if((wt+dis)==dist[y]){
                    c[y]=(c[y]+c[node])%mod;
                }
                
            }
        }
        return c[n-1];
    }
};