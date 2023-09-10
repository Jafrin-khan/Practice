class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        sort(intervals.begin() , intervals.end());
        
        int n = intervals.size();
        vector<vector<int>> ans;
        
        int i = 0;
        while(i < n){
            if(ans.empty()) ans.push_back(intervals[i]);
            else{
                vector<int>& v = ans.back();
                if(intervals[i][0] <= v[1]) v[1] = max(v[1] , intervals[i][1]);
                else ans.push_back(intervals[i]);
            }
            i++;
        }
        
        return ans;
        
    }
};