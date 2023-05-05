class Solution {
public:
    
    /*
    TC = O(NlogN)
    SC = O(2)
    */
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        vector<vector<int>> ans;
        sort(intervals.begin() , intervals.end());
        for(auto v : intervals){
            if(ans.empty()) ans.push_back(v);
            else{
                vector<int> &vBack = ans.back();
                if(vBack[1] >= v[0]){
                    
                    vBack[1] = max(vBack[1] , v[1]);
                }
                else ans.push_back(v);
            }
        }
        
        return ans;
    }
};