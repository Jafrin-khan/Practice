class Solution {
public:

//Recursion solution
vector<vector<int>> res;
vector<vector<int>> combine(int n, int k) {

if( k > n) return res;

vector<int> cand;

solve(1,k,n,cand);

return res;
}

void solve(int start, int k, int n, vector<int>& cand){
if(cand.size()==k){
res.push_back(cand);
return;
}

for(int i = start; i <= n ; i++){
cand.push_back(i);
solve(i+1,k,n,cand);
cand.pop_back();
}
}
};