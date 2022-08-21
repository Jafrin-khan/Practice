class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int n = matrix.size();
        int m = matrix[0].size();
        
        for(int i = 0 ; i < n ; i++){
            
            if(matrix[i][m-1] >= target && matrix[i][0] <= target){
                
                int low = 0;
                int high = matrix[0].size();
                
                while(low <= high){
                    
                    int mid = (low + high)/2;
                    if(matrix[i][mid] == target){
                        return true;
                    }
                    
                    else if(matrix[i][mid] < target){
                        low = mid+1;
                    }
                    
                    
                    else{
                        high = mid-1;
                    }
                    
                }
            }
        }
        
        return false;
    }
};