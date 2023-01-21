class Solution {
public:
    
    /*
    Input : [90,47,69,10,43,92,31,73,61,97]
    Output : 9
    
    Dry run with this TC as well
    */
    int partitionDisjoint(vector<int>& nums) {
        
        int n = nums.size();
        int maxFirst = nums[0];
        int curr = nums[0];
        int len = 1;
        
        for(int i = 1 ; i < n ; i++){
            
            if(nums[i] < maxFirst){
                maxFirst = curr;
                len = i+1;
            }
            
            else if(nums[i] > curr){
                curr = nums[i];
            }
      
        }
     
        return len;
    }
};