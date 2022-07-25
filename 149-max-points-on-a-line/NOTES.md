class Solution {
public:
int maxPoints(vector<vector<int>>& points) {
int n = points.size(), ans =1; // ans=1 if size is 1
for(int i=0;i<n-1;i++){
unordered_map<double, int> m; // map to store count of different slopes
for(int j=i+1;j<n;j++){ // starting from i+1, since previous point would have already included in the answer if it lies on the longest staright lines
// calculating slopes
double slope = ((double)(points[j][1]-points[i][1])/(double)(points[j][0]-points[i][0]));
// if slope is -inf then converting it to +inf, for cases like [[0,1],[0,0],[0,4],[0,-2],[0,-1],[0,3],[0,-4]]
if(slope==(-1/double(0)))slope=(1/double(0));
m[slope]++;
}
// iterating over the map to get the maximum number of points that lie on the same straight line
for(auto &it:m){
ans = max(ans, it.second+1); // it.second (+ 1) to include the current coordinate
}
}
return ans;
}
};