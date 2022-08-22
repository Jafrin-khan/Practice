class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        vector<vector<int>> ans;
        set<vector<int>> st;
        sort(nums.begin() , nums.end());
        
        for(int i = 0 ; i < nums.size() ; i++){
            
            if(i > 0 && nums[i] == nums[i-1]){
                continue;
            }
            
            int low = i+1;
            int high = nums.size()-1;
            
            int toFind = 0 - nums[i];
            
            while(low < high){
                
                if(nums[low] + nums[high] == toFind){
                    
                    vector<int> v;
                    v.push_back(nums[i]);
                    v.push_back(nums[low]);
                    v.push_back(nums[high]);
                   
                    
                    st.insert(v);
                    low++;
                    high--;
                    
                    
                }
                
                else if(nums[low] + nums[high] < toFind){
                    low++;
                }
                
                else{
                    high--;
                }
            }
        
        }
        
        for(auto x : st){
            ans.push_back(x);
        }
        
        return ans;
        
    }
};