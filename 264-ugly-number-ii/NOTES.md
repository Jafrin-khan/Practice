void f(set<long int>& st , long int n){
if(n > INT_MAX){
return;
}
if(st.find(n) != st.end()){
return;
}
st.insert(n);
f(st , n*2);
f(st , n*3);
f(st , n*5);
return;
}
int nthUglyNumber(int n) {
set<long int> st;
f(st , 1);
int i = 0;
for(auto it : st){
i++;
if(i==n) return it;
}
return i;
}