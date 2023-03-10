class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        
        int n = queries.size();
        vector<int> ans;
        int sum = 0;
        
        for(int i = 0 ; i < n ; i++) if(nums[i]%2 == 0) sum += nums[i];
        
        for(int i = 0 ; i < n ; i++){
            int val = queries[i][0];
            int ind = queries[i][1];
            if(abs(nums[ind])%2 == 0) sum -= nums[ind];
            nums[ind] += val;
            if(abs(nums[ind])%2 == 0) sum += nums[ind];
            ans.push_back(sum);
        }
        
        return ans;
        
    }
};