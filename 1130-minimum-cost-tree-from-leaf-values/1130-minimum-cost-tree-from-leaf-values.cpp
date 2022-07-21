class Solution {
public:
    
    // for explanation refer this if confused
    // https://www.youtube.com/watch?v=pYs3qj42h3c
    
    map<pair<int,int> , pair<int,int>>dp;
    
    pair<int,int> f(vector<int>& arr , int s , int e){
        
        if(s == e){
            return {arr[s] ,0};
        }
        
        int leafMax = INT_MIN;
        int minSum = INT_MAX;
        
       if(dp.count({s,e})){
           return dp[{s,e}];
       }
        
        for(int i = s ; i < e ; i++){
            
            auto left = f(arr,s,i);
            auto right = f(arr,i+1,e);
            
            leafMax = max(left.first,right.first);
            minSum = min(minSum , left.second + right.second + (left.first*right.first));
        }
        
      
        return dp[{s,e}] = {leafMax,minSum};
        
    }
    int mctFromLeafValues(vector<int>& arr) {
       
        int n = arr.size();
     
       return f(arr,0,arr.size()-1).second;
    }
};