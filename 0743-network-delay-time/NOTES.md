int networkDelayTime(vector<vector<int>>& times, int n, int k) {
using ip=pair<int,int> ;
vector<vector<ip>> adjlist(n+1);
//MAKE GRAPH
for(auto ele:times){
adjlist[ele[0]].push_back({ele[1],ele[2]});
}
priority_queue<ip,vector<ip>,greater<ip> > pq;
vector<int> dist(n+1,INT_MAX);
vector<bool> visited(n+1,false);
dist[k]=0;
pq.push({0,k}); // pair in pq->distance,node;
while(!pq.empty()){
//fetch currently minimum distance node and traverse its neighbours
// and update distances
int node=pq.top().second;
int cost=pq.top().first;
visited[node]=true;
pq.pop();
for(auto ele : adjlist[node]){
//visited[ele.second]=true;
int next_node=ele.first;
int cost=ele.second;
//update min distance to neighbournode via currentnode
if(!visited[next_node] && dist[next_node]>dist[node]+cost){
dist[next_node]=dist[node]+cost;
pq.push({dist[next_node],next_node});
}
}
}
int ans=INT_MIN;
for(int i=1;i<dist.size();i++) ans=max(ans,dist[i]);
if(ans==INT_MAX) return -1; else return ans;
}