class DisjointSet{
    public:
    vector<int> size , parent;
  
    DisjointSet(int n){
        size.resize(n+1 , 1);
        parent.resize(n+1);

        for(int i = 0 ; i <= n ; i++){
            parent[i] = i;
        }
    }

    int findUPar(int node){
    
        if(node == parent[node]){
            return node;
        }
        return parent[node] = findUPar(parent[node]);
    }

    void unionBySize(int u , int v){
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);

        if(ulp_u == ulp_v){
            return;
        }

        if(size[ulp_u] < size[ulp_v]){
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }

        else{
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};


class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& details) {
        
          
        int n = details.size();
        unordered_map<string,int> mp;
        
        DisjointSet ds(n);
        
        for(int i = 0 ; i < n ; i++){
            for(int j = 1 ; j < details[i].size() ; j++){
                string mail = details[i][j];
                if(mp.find(mail) == mp.end()){
                    mp[mail] = i;
                }
                
                else{
                    ds.unionBySize(i , mp[mail]);
                }
            }
        }
        
        vector<string> mergedMail[n];
        for(auto it : mp){
            string mail = it.first;
            int node = ds.findUPar(it.second);
            mergedMail[node].push_back(mail);
        }
        
        vector<vector<string>> ans;
        
        for(int i = 0 ; i < n ; i++){
            if(mergedMail[i].size() == 0){
                continue;
            }
            
            sort(mergedMail[i].begin() , mergedMail[i].end());
            vector<string> temp;
            temp.push_back(details[i][0]);
            for(auto it : mergedMail[i]){
                temp.push_back(it);
            }
            
            ans.push_back(temp);
        }
        
        return ans;
    }
};