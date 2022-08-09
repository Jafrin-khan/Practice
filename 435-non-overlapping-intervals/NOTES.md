sort(intervals.begin() , intervals.end());
int mini = intervals[0][1];
int cnt = 0;
for(int i = 1 ; i < intervals.size() ; i++){
if(intervals[i][0] < mini){
cnt++;
mini = min(mini , intervals[i][1]);
continue;
}
mini = intervals[i][1];
}
return cnt;