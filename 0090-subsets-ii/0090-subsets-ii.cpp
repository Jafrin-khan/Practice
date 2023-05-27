class Solution {
public:
/* ///BRUTE
    
// Time Complexity: O( 2^n *(k log (x) )). 2^n  for generating every subset and k* log( x)  to insert every combination of average length k in a set of size x. 

// Space Complexity:  O(2^n * k) to store every subset of average length k. Since we are initially using a set to store the answer another O(2^n *k) is also used.
    
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
     
*/
    
    //OPTIMISED
    /*
Time Complexity: O(2^n) for generating every subset and O(k)  to insert every subset in another data structure if the average length of every subset is k. Overall O(k * 2^n).

Space Complexity: O(2^n * k) to store every subset of average length k. Auxiliary space is O(n)  if n is the depth of the recursion tree.
    */
    
     vector<vector<int>> ans;
    
    void f(int ind , vector<int> helper , vector<int>& nums){
        
       
        ans.push_back(helper);
           
        for(int i = ind ; i < nums.size() ; i++){
            
            if(i != ind && nums[i] == nums[i-1]){
                continue;
            }
            
            helper.push_back(nums[i]);
            f(i+1 , helper , nums);
            helper.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        
        sort(nums.begin() , nums.end());
        vector<int> helper;
        f(0 , helper , nums);
        
        return ans;
        
    }

};