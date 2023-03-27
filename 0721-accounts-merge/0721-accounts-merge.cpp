class DisjointSet{
    public:
    vector<int> parent;
    vector<int> size;
    
    DisjointSet(int v){
        parent.resize(v+1);
        size.resize(v+1 , 1);
        for(int i = 0 ; i <= v ; i++){
            parent[i] = i;
        }
    }
    
    int findUPar(int node){
        if(node == parent[node]) return node;
        return parent[node] = findUPar(parent[node]);
    }
    
    void unionBySize(int u , int v){
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if(ulp_v == ulp_u) return;
        
        if(size[ulp_u] <= size[ulp_v]){
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

    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        
       int n = accounts.size();
       DisjointSet ds(n);
        
       unordered_map<string , int> mp;//<email , user(depicted by node)>
        
       for(int i = 0 ; i < n ; i++){
           for(int j = 1 ; j < accounts[i].size() ; j++){
               string mail = accounts[i][j];
               if(mp.find(mail) == mp.end()) mp[mail] = i;
               else ds.unionBySize(i , mp[mail]);//merging both the users as they are same
           }
       }
        
       vector<string> mergedMails[n];
        
       for(auto it : mp){
           string mail = it.first;
           int node = ds.findUPar(it.second);
           
           mergedMails[node].push_back(mail);//humne abhi sirf users ko link kra tha DSU se ab hum linked users (mtlb jo same user tha lekin record alag padga tha....i,e, alg ind pai islie humne us user ko ek hi ind se merge krwaya jo hmara ultimate parent hai aur ab us ultimate parent k corresponding hum emails ko push krteyy jaare
           
       }
        
       vector<vector<string>> ans;
        
       for(int i = 0 ; i < n ; i++){
           if(mergedMails[i].size() == 0) continue;
           sort(mergedMails[i].begin() , mergedMails[i].end());
           
           vector<string> temp;
           temp.push_back(accounts[i][0]);//user push krna hoga phele
           for(auto it : mergedMails[i]) temp.push_back(it);//ab user user k corresponding daari mails daaldo temp mai jo hum ans mai push krenge
           ans.push_back(temp);
       }
      
        return ans;
    }
};