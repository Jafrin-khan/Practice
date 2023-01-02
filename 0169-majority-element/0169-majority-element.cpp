class Solution {
public:
    /*
    TC = O(N)
    SC = O(N)
    */
    int majorityElement(vector<int>& nums) {
        
        unordered_map<int , int> mp;
        int n = (nums.size()/2) + 1;
        
        for(int i = 0 ; i < nums.size() ; i++){
            mp[nums[i]]++;
        }
        
        for(auto it : mp){
            if(it.second >= n){
                return it.first;
            }
        }
        
        return -1;
        
    }
};