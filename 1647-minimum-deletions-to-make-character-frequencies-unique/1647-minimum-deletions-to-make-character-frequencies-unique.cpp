class Solution {
public:
    int minDeletions(string s) {
        
        priority_queue<int>pq;
        unordered_map<int,int> mp;
        
        for(int i = 0 ; i < s.size() ; i++){
            mp[s[i]]++;
        }
        
        for(auto x : mp){
            pq.push(x.second);
        }
        
        int cnt = 0;
        
        while(!pq.empty() && pq.top() != 0){
            
            int top = pq.top();
            pq.pop();
            if(!pq.empty() && pq.top() == top){
                cnt++;
                top--;
                pq.push(top);
            }
        }
        
        return cnt;
    }
};