class Solution {
public:
    int thirdMax(vector<int>& nums) {
        int k = 3;
        int maxi = nums[0];
         priority_queue<int , vector<int> , greater<int>> pq;
         unordered_map<int,int> mp;
        
        for(int i = 0 ; i < nums.size() ; i++){
            
            if(mp.find(nums[i]) != mp.end()){
                continue;
            }
            
            maxi = max(maxi , nums[i]);
            pq.push(nums[i]);
            if(pq.size() > k){
                pq.pop();
            }
            
            mp[nums[i]]++;
        }
        
        if(nums.size() < k || pq.size() < k){
            return maxi;
        }
        
        return pq.top();
        
    }
};