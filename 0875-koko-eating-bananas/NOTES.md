bool helper(vector<int> &piles,int h,int k)
{
int time = 0;
for(auto &pile : piles)
time += ceil( double(pile)/k );
return time <=h;
}
int minEatingSpeed(vector<int>& piles, int h) {
int low = 1;
int high = *max_element(piles.begin(),piles.end());
while(low <= high)
{
int mid = low + (high - low)/2;
helper(piles,h,mid) ? high = mid-1 : low = mid+1;
}
return low;
}