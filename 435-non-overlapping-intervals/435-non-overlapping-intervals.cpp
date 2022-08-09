class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        
        sort(intervals.begin() , intervals.end());
        int n = intervals.size();
        
        int i = 1;
        int b = intervals[0][1];
        
        int cnt = 0;
        
        while(i < n){
            
        if( b > intervals[i][0]){
           
                b = min(b , intervals[i][1]);
                cnt++;
                i++;continue;
            }
            
        
            
        if(i < n){
            b = intervals[i][1];
            i++;
        }
            
            
        }
        
        return cnt;
        
    }
};