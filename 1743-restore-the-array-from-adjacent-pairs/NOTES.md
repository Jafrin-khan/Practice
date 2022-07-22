void dfs(map<int,vector<int>> &m , set<int> &st , int a , vector<int> &ans){
if(st.find(a) != st.end()){
return;
}
ans.push_back(a);
st.insert(a);
for(auto x : m[a]){
dfs(m , st , x , ans);
}
}
vector<int> restoreArray(vector<vector<int>>& A) {
map<int,vector<int>> mp;
for(auto a : A){
mp[a[0]].push_back(a[1]);
mp[a[1]].push_back(a[0]);
}
int head;
for(auto a : mp){
if( a.second.size() == 1){
head = a.first;
}
}
vector<int> ans;
set<int> visited;
dfs(mp , visited , head , ans);
return ans;
}