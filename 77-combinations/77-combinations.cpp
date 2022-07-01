class Solution {
public:
    
   
    
    void f(int ind , int n , int k , vector<int> v ,  vector<vector<int>>& ans){
        
        if(k == v.size()){
            ans.push_back(v);
            return;
        }
        
      
        for(int i = ind ; i <= n ; i++){
            v.push_back(i);
            f(i+1 , n , k , v , ans);
            v.pop_back();
        }
        
    }
    vector<vector<int>> combine(int n, int k) {
        
         vector<vector<int>> ans;
         vector<int> v;
        
         f(1 , n , k , v , ans);
        
         return ans;
    }
};