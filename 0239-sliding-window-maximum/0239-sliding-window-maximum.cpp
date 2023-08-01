class Solution {
public: 
    
//             0 1  2  3 4 5 6 7
//     nums = [1,3,-1,-3,5,3,6,7], k =  3
//                               |           
        
//     dequeue ->  store ind  -> 6 7  
    
        
//     ans -> 3 3 5 5 6 7
        
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
        deque<int> dq;
        vector<int> ans;
        
        for(int i = 0 ; i < nums.size() ; i++){
             if(!dq.empty() && dq.front() <= i-k){/////////////////////
                dq.pop_front();
            }
            while(!dq.empty() && nums[dq.back()] <= nums[i]){
                dq.pop_back();
            }
            
            dq.push_back(i);
            if(i >= k-1) ans.push_back(nums[dq.front()]);
        }
        
        return ans;
    }
};