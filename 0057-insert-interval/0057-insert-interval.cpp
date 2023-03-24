class Solution {
public:
     vector<vector<int>> merge(vector<vector<int>>& v) {
        
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
    vector<vector<int>> insert(vector<vector<int>>& v, vector<int>& nI) {
        int n = v.size();
     
        vector<vector<int>> ans;
        int pos = -1;
        
        for(int i = 0 ; i < n ; i++){
            if(v[i][0] >= nI[0]){pos = i;break;}
            
        }
        int i = 0;
        
        while(i < n){
            if(pos == i) {ans.push_back(nI);pos = -2;}
            else{ ans.push_back(v[i]);i++;}
        }
        
        if(pos == -1) ans.push_back(nI);
         
        return merge(ans);
    }
};