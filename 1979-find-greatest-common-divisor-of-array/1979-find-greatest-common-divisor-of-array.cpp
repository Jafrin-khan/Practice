class Solution {
public:
    
    int getGCD(int a , int b){
        
        if(a == 0){
            return b;
        }
        
        if(b == 0){
            return a;
        }
        
        return getGCD(b,a%b );
    }
    int findGCD(vector<int>& nums) {
        
        int smallest = nums[0];
        int largest = nums[0];
        
        for(int i = 0 ; i < nums.size() ; i++){
            smallest = min(smallest , nums[i]);
            largest = max(largest , nums[i]);
        }
        
        int GCD = getGCD(smallest , largest);
        
        return GCD;
        
    }
};