class Solution {
public:
    int maxArea(vector<int>& height) {
        
        int i = 0;
        int j = height.size()-1;
        
        int water = -1e9;
        
        while(i < j){
            
            int left = height[i];
            int right = height[j];
            
            water = max(water , (j-i)*min(left , right));
            
            if(left > right){
                j--;
            }
            
            else{
                i++;
            }
        }
        
        return water;
        
    }
};