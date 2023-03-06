class Solution {
public:
    
    /*
    TC = O(N) + O(M*N)
    SC = O(N*N)...check this
    */
    bool static cmp(vector<int>& a , vector<int>& b){
        return a[1] >= b[1];
    }
    
    int maxProfitAssignment(vector<int>& diff, vector<int>& profit, vector<int>& worker) {
        
        int n = profit.size();
        int m = worker.size();
        
        vector<vector<int>> factors;
        for(int i = 0 ; i < n ; i++){
            factors.push_back({diff[i],profit[i]});
        }
        
        sort(factors.begin() , factors.end(),cmp);
        
        int j = 0 , ans = 0;
        while(j < m){
             int i = 0;
             while(i < n && factors[i][0] > worker[j]){
                 i++;
             }
            if(i < n) ans += factors[i][1];
            j++;
        }
        return ans;
    }
};