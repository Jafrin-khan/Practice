class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        
        int n = nums.size();
        
        int slow = nums[0];
        int fast = nums[0];
        
        do{
            slow = nums[slow];
            fast = nums[nums[fast]];    
        }while(slow != fast);//////////
        
        slow = nums[0];/////////////
        while(slow != fast){//////////////
            slow = nums[slow];/////////
            fast = nums[fast];//////////
        }
        
        return slow;//////////
    }
};

//  0   1   2   3   4
// [1 , 3 , 4 , 2 , 2]
 
// slow = 4;
// fast = 4;

// slow = nums[slow]
// fast = nums[nums[fast]]
