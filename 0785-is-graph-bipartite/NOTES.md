//TC aur explanation pichle submission mai
bool dfs(int node , int color , vector<vector<int>>& adj , vector<int>& col){
col[node] = color;
for(auto it : adj[node]){
if(col[it] == -1){
if(!dfs(it , 1- color, adj , col)) return false;
}
else{
if(color == col[it]) return false;
}
}
return true;
}
bool isBipartite(vector<vector<int>>& adj) {
int n = adj.size();
vector<int> col(n,-1);
for(int i = 0 ; i < n ; i++){
if(col[i] == -1){
if(!dfs(i , 0 , adj , col)) return false;
}
}
return true;
}