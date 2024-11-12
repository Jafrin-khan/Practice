class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        
        stack<int> st;
        
        for(int i = nums2.size()-1 ; i >= 0 ; i--){
                while(!st.empty() && st.top() < nums2[i]) st.pop();
                    
                    auto it = find(nums1.begin() , nums1.end() , nums2[i]);
                    if(it != nums1.end()){
                       int ind = it - nums1.begin();
                        
                       if(st.empty()) nums1[ind] = -1;
                       else nums1[ind] = st.top();
                        
                }
            
            st.push(nums2[i]);
        }
        
        return nums1;
    }
};