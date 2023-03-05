class Solution {
public:
    
    /*
    TC = O(N)
    SC = O(N)
    */
    int maxWidthRamp(vector<int>& nums) {
        stack<int> st;
        //storing chote number k ind
        for(int i = 0 ; i < nums.size() ; i++){
            if(st.empty() || nums[st.top()] > nums[i]) st.push(i);
        }
        
        int ans = 0;
        //bade waale numbers se compare krke largest width calc krna...traverse RHS se krenge
        for(int i = nums.size()-1 ; i > ans ; i--){ // agr i ans se chotu h to mtlb aur traverse krne ki zaroorat ni 
            while(!st.empty() && nums[st.top()] <= nums[i]){
                ans = max({ans , i - st.top()});st.pop();
            }
        }
        
        return ans;
    }
};