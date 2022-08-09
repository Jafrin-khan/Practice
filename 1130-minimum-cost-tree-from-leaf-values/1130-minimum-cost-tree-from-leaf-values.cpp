class Solution {
public:
    
     map<pair<int,int> , pair<int,int>>dp;
    pair<int,int> f(int s , int e , vector<int>& arr){
        
        if(s == e){
            return {arr[s],0};
            //zero bcoz it doesnt have left or right leaf hence their product will be zero eventually as they dont exist
        }
        
        int leafMax = INT_MIN;
        int minSum = INT_MAX;
        
         
       if(dp.count({s,e})){
           return dp[{s,e}];
       }
        
        
        for(int i = s ; i < e ; i++){
            
            auto left = f(s , i , arr);
            auto right = f(i+1 , e , arr);
            
            
            
            leafMax =  max(left.first,right.first);
            
            minSum = min(minSum , left.second + right.second + (left.first*right.first));
        }
        
        return dp[{s,e}] ={leafMax,minSum};
        
    }
    int mctFromLeafValues(vector<int>& arr) {
        
        return f(0 , arr.size()-1 ,arr).second;
        
    }
};