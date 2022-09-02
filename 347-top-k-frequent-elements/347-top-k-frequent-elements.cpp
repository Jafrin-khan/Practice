class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        unordered_map<int,int> mp;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq; //fre->num
        
        for(int i = 0 ; i < nums.size() ; i++){
            mp[nums[i]]++;
        }
        
        for(auto x : mp){
            pq.push({x.second , x.first});
            
            if(pq.size() > k){
                pq.pop();
            }
        }
        
        vector<int> ans;
        
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        
        return ans;
        
    }
};