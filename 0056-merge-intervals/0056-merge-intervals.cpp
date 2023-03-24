class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& v) {
        
        sort(v.begin() , v.end());
        
        vector<vector<int>> ans;
        int i = 0;
        
        while(i < v.size()){
           
            if(!ans.empty()){
                vector<int> &backV = ans.back();
                if(backV[1] >= v[i][0]) backV[1] = max(backV[1] , v[i][1]);
                else ans.push_back(v[i]);  
            }
            
            else ans.push_back(v[i]);
            i++;
        }
        
        return ans;
        
    }
};