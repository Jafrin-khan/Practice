class Solution {
public:
    int trap(vector<int>& height) {
        
        int l = 0;
        int r = height.size()-1;
        
        int left = 0;
        int maxLeft = 0;
        
        int right = 0;
        int maxRight = 0;
        
        int ans = 0;
        
        while(l <= r){
            
            if(left <= right){
                left = height[l++];
                
                if(maxLeft < left){
                    maxLeft = left;
                }
                
                else{
                    ans += maxLeft - left;
                }
            }
            
            else{
                right = height[r--];
                
                if(maxRight < right){
                    maxRight = right;
                }
                
                else{
                    ans += maxRight - right;
                }
            }
        }
        
        return ans;
        
    }
};