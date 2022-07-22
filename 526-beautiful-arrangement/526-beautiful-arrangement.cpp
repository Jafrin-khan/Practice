class Solution {
public:
    //https://www.youtube.com/watch?v=xf8qAkqDr8Y
    
    int ans = 0;
    
    void dfs(vector<int> nums , int start , int end){
        
        if(start > end){
            ans++;
            return;
        }
        
        for(int i = 1 ; i <= end ; i++){
            if(nums[i] == 0 && (start%i == 0 || i%start == 0)){
                nums[i] = start;
                dfs(nums , start+1 , end);
                nums[i] = 0;
            }
        }
    }
    
    
    int countArrangement(int n) {
        
        vector<int> nums(n+1 , 0);
        dfs(nums , 1 , n);
        
        return ans;
        
    }
};