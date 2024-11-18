class Solution {
public:
    int trap(vector<int>& h) {
        
        vector<int> leftMax;
        vector<int> rightMax;
        
        int maxi = 0;
        
        for(int i = 0 ; i < h.size() ; i++){
            maxi = max(maxi , h[i]);
            leftMax.push_back(maxi);
        }
        
        maxi = 0;
        int ans = 0;
        
        for(int i = h.size()-1 ; i >= 0 ; i--){
            maxi = max(maxi , h[i]);
            rightMax.push_back(maxi);
        }
        
        reverse(rightMax.begin() , rightMax.end());
        
        for(int i = 0 ; i < h.size() ; i++){
            ans += min(leftMax[i],rightMax[i]) - h[i];
        }
        
        return ans;

    }
};