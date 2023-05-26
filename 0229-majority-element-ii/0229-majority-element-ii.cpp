class Solution {
public:
    
    /*
    MOORE'S VOTING ALGO
    TC = O(N)
    SC = O(1)
    */
    
    //ye if else conditions line 19 aur 20 ki hamesha pehle aani h remember it VVVVVIMP
    vector<int> majorityElement(vector<int>& nums) {
        
        int ele1 = -1e9;
        int ele2 = -1e9;
        int cnt1 = 0 , cnt2 = 0;
        
        for(int i = 0 ; i < nums.size() ; i++){
            
            if(ele1 == nums[i]) cnt1++;
            else if(ele2 == nums[i]) cnt2++;
            
            else if(cnt1 == 0){
                cnt1 = 1;
                ele1 = nums[i];
            }
            
            else if(cnt2 == 0){
                cnt2 = 1;
                ele2 = nums[i];
            }
            
          
            
            else{
                cnt1--;
                cnt2--;
            }
            
        }
        
        cnt1 = 0;
        cnt2 = 0;
        
        for(auto it : nums){
            if(it == ele1) cnt1++;
            if(it == ele2) cnt2++;
        }
        
        vector<int> ans;
        
        if(cnt1 > (nums.size()/3)) ans.push_back(ele1);
        if(cnt2 > (nums.size()/3)) ans.push_back(ele2);
        
        return ans;
    }
};