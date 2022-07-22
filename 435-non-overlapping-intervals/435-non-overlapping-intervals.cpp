class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        
        sort(intervals.begin() , intervals.end());
        int mini = intervals[0][1];
        int cnt = 0;
        for(int i = 1 ; i < intervals.size() ; i++){
            
            if(intervals[i][0] < mini){
                cnt++;
                mini = min(intervals[i][1],mini);
                continue;
            }
            
            mini = intervals[i][1];
            
            
        }
        
        return cnt;
        
    }
};