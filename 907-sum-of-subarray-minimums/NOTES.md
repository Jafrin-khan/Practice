int sumSubarrayMins(vector<int>& arr) {
int N = arr.size();
stack<int> monoUp; // store index of arr
long long ans = 0;
for (int i = 0; i <= N; ++i) {
while (!monoUp.empty() && (i==N||arr[i] < arr[monoUp.top()])){
int tmpi = monoUp.top();
monoUp.pop();
int tmpi1 = monoUp.empty() ? -1 : monoUp.top();
// all the subarrays in range [tmpi1, i] including tmpi has arr[tmpi] as minimum value
ans += arr[tmpi] * (long long)(tmpi-tmpi1)*(i-tmpi);
}
monoUp.push(i);
}
ans = ans % (int)(1e9 + 7);
return (int)ans;
}