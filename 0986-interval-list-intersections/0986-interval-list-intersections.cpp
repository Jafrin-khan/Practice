class Solution {
public:
    /*
    TC = O(n)
    SC = O(1)
    */
    vector<vector<int>> intervalIntersection(vector<vector<int>>& l1, vector<vector<int>>& l2) {
        
        vector<vector<int>> ans;
        int n = l1.size();
        int m = l2.size();
        
        int i = 0;
        int j = 0;
        
        while(i < n && j < m){
            if(l1[i][0] > l2[j][1]) j++;
            else if(l1[i][1] < l2[j][0]) i++;
            else{
            int l = max(l1[i][0],l2[j][0]);
            int r = min(l1[i][1],l2[j][1]);
            ans.push_back({l,r});
            if(l1[i][1] < l2[j][1]) i++;
            else j++;
        }
               }        
        return ans;
    }
};