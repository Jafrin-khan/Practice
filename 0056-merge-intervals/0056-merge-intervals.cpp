class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        if(intervals.size() == 1) return intervals;
        
        sort(intervals.begin() , intervals.end());
        
        vector<vector<int>> ans;
        ans.push_back(intervals[0]);
        
        int n = intervals.size();
        int i = 1;
        
        while(i < n){
          vector<int>& v = ans.back();
          
           if(v[1] >= intervals[i][0]) v[1] = max(v[1] , intervals[i][1]);
            else ans.push_back(intervals[i]);
            i++;
           
        }
        
     
        
        return ans;
        
    }
};