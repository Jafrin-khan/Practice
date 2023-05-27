class Solution {
public:
    /*
Time Complexity: O( 2^n *(k log (x) )). 2^n  for generating every subset and k* log( x)  to insert every combination of average length k in a set of size x. 

Space Complexity:  O(2^n * k) to store every subset of average length k. Since we are initially using a set to store the answer another O(2^n *k) is also used.
    */
    void f(int ind , vector<int>& nums , vector<int> helper , set<vector<int>>& st){
        if(ind < 0){
            sort(helper.begin() , helper.end());
            st.insert(helper);
            return;
        }
        
        //take
        helper.push_back(nums[ind]);
        f(ind-1 , nums , helper , st);
        helper.pop_back();
        
        //notTake
        f(ind-1 , nums , helper , st);
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        
        int n = nums.size();
        
        vector<int> helper;
        set<vector<int>> st;
        
        f(n-1 , nums , helper , st);
        
        vector<vector<int>> ans;
        for(auto it : st){
            ans.push_back(it);
        }
        
        return ans;
    }
};