class Solution {
public:
    
    //https://www.youtube.com/watch?v=emF5eAYR3Nk
    
    void dfs(int node , set<int>& st ,map<int,vector<int>>& mp , vector<int>& ans){
        
        if(st.find(node) != st.end()){
            return;
        }
        
        ans.push_back(node);
        st.insert(node);
        
        for(auto x : mp[node]){
            dfs(x , st , mp,ans);
        }
    }
  
    vector<int> restoreArray(vector<vector<int>>& A) {
        
       map<int,vector<int>> mp;
        
       for(auto x : A){
           mp[x[0]].push_back(x[1]);
           mp[x[1]].push_back(x[0]);
       }
        
      
        set<int> visited;
        vector<int> ans;
        
        
        int head;
        for(auto x : mp){
            if(x.second.size() == 1){
                head = x.first;
            }
        }
        
        dfs(head , visited , mp , ans);
        
        return ans;
    }
};