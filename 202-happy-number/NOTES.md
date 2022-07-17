int getSquare(int n){
int square = 0;
while(n!=0){
square += (n%10)*(n%10);
n/=10;
}
return square;
}
bool isHappy(int n) {
unordered_map<int,int> mp;
while(mp.find(n) == mp.end()){
int elem = getSquare(n);
mp[n] = elem;
n = mp[n];
if(n == 1){
return true;
}
}
return false;
}