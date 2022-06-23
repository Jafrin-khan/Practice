class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        
        unordered_map<int,int> mp;
        stack<int> st;
        
        reverse(nums2.begin(),nums2.end());
        
        for(int i = 0 ; i < nums2.size() ; i++){
            
            while(!st.empty() && st.top() < nums2[i]){
                st.pop();
            }
            
            if(st.empty()){
                mp[nums2[i]] = -1;
            }
            
            if(!st.empty() && st.top() > nums2[i]){
                mp[nums2[i]] = st.top();
            }
            
            st.push(nums2[i]);
        }
        
        vector<int> ans;
        
        for(int i = 0 ; i < nums1.size() ; i++){
            
            if(mp.find(nums1[i]) != mp.end()){
                ans.push_back(mp[nums1[i]]);
            }
        }
        
        return ans;
    }
};