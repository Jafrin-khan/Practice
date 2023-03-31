long long zeros(long long x) {
long long ans = 0;
long long i = 5;
while(i <= x) {
ans += x / i;
i = i * 5;
}
return ans;
}
int preimageSizeFZF(int k) {
long long start = 0;
long long end = (long long) k * 10;
long long mid = (start + end) / 2;
while(start <= end) {
int zs = zeros(mid);
if(zs == k) {
return 5;
} else if(zs < k) {
start = mid + 1;
} else {
end = mid - 1;
}
mid = (start + end) / 2;
}
return 0;
}