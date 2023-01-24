class Solution {
public:
    int trap(vector<int>& height) {
        
        int ans = 0;
        
        int maxLeft = 0;
        int maxRight = 0;
        int left = 0;
        int right = height.size()-1;
        
        while(left < right){
            
            if(height[left] <= height[right]){
                if(height[left] > maxLeft) maxLeft = height[left];
                else ans += (maxLeft - height[left]);
                left++;
            }
            else{
                if(height[right] > maxRight) maxRight = height[right];
                else ans += (maxRight - height[right]);
                right--;
            }
        }
        return ans;
    }
};