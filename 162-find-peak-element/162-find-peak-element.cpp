class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        
        priority_queue<pair<int,int>> pq;
        
        for(int i = 0 ; i < nums.size() ; i++){
            pq.push({nums[i],i});
        }
        
        return pq.top().second;
    }
};