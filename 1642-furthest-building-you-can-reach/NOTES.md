int i = 0;
priority_queue<int> pq;
for(i = 1 ; i < h.size() ; i++){
if(h[i] - h[i-1] > 0){
int diff = h[i] - h[i-1];
pq.push(diff);
b-= diff;
if(b < 0){
b += pq.top();
pq.pop();
if(l == 0){
return i-1;
}
l--;
}
}
}
return h.size()-1;