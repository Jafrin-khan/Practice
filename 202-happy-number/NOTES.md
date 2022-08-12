int get(int num){
int ans = 0;
int n = num;
while(n!=0){
ans += (n%10)*(n%10);
n/=10;
}
return ans;
}
bool isHappy(int n) {
unordered_map<int,int> mp;
while(mp.find(n) == mp.end()){
int elem = get(n);
mp[n] = elem;
n = elem;
if(n == 1){
return true;
}
}
return false;
}