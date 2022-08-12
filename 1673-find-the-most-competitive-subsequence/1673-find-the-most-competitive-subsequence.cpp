class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        
        priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>>> pq;
        
        for(int i = 0 ; i <= nums.size()-k ; i++){
            pq.push({nums[i] , i});
        }
        
        vector<int> ans;
        int ind = -1;
        
        while(k--){
            
            while(pq.top().second <= ind){
                pq.pop();
            }
            ans.push_back(pq.top().first);
            ind = pq.top().second;
            
            if(k){
                pq.push({nums[nums.size()-k] , nums.size()-k});
            }
            
        }
        
        return ans;
        
    }
};