class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        vector<vector<int>> ans;
        
        sort(intervals.begin() , intervals.end());
        
        int n = intervals.size();
        ans.push_back(intervals[0]);
        int p = 0;
        for(int i = 1 ; i < n ; i++){
            
        
            if(intervals[i][0] <= ans[p][1]){
                ans[p][1] = max(ans[p][1] , intervals[i][1]);
                continue;
            }
            
            else{
                ans.push_back(intervals[i]);
                p++;
            }
            
        }
        
        return ans;
        
    }
};