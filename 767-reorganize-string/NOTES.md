string reorganizeString(string s) {
unordered_map<char,int> mp;
priority_queue<pair<int,int>> pq;
for(int i = 0 ; i < s.size() ; i++){
mp[s[i]]++;
}
for(auto x : mp){
pq.push({x.second , x.first});
}
string ans = "";
while(pq.size() > 1){
auto top1 = pq.top();
pq.pop();
auto top2 = pq.top();
pq.pop();
ans += top1.second;
ans += top2.second;
top1.first--;
top2.first--;
if(top1.first > 0){
pq.push(top1);
}
if(top2.first > 0){
pq.push(top2);
}
}
if(pq.size() == 1){