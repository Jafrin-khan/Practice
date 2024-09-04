class Solution {
public:
    
    void reverse(int start , int end , vector<int>& nums){
        
        while(start <= end){
            int temp = nums[start];
            nums[start] = nums[end];
            nums[end] = temp;
            start++;
            end--;
        }
    }
    
    void rotate(vector<int>& nums, int k) {
        
        int n = nums.size();
        k = k%n;
        
        if(k > n || n == 0 || n == 1) return;
        reverse(0 , n-k-1 , nums);
        reverse(n-k , n-1 , nums);
        reverse(0 , n-1 , nums);
       
        
    }
};