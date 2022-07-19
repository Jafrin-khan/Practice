priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
vector<int> res;
int indx = -1,i=0;
for(int i=0;i<=nums.size()-k;i++){
pq.push({nums[i],i});
}
while(k--){
while(pq.top().second<=indx) pq.pop();
res.push_back(nums[pq.top().second]);
indx = pq.top().second;
if(k)
pq.push({nums[nums.size()-k],nums.size()-k});
}
return res;