class Solution {
public:
    int evalRPN(vector<string>& nums) {
        
        stack<int> st;
        
        for(int i = 0 ; i < nums.size() ; i++){
            
           if(nums[i] == "+" || nums[i] == "/" || nums[i] == "*" || nums[i] == "-"){
               
               int top1 = st.top();
               st.pop();
               int top2 = st.top();
               st.pop();
               
               if(nums[i] == "+"){
                   st.push(top1 + top2);
               }
               
               else if(nums[i] == "-"){
                   st.push(top2 - top1);
               }
               
               else if(nums[i] == "*"){
                   st.push(top2 * top1);
               }
               
               else{
                   st.push(top2 / top1);
               }
           }
            
           else{
               st.push(stoi(nums[i]));
           }   
        }
        
        int ans = st.top();
        st.pop();
        
        return ans;
    }
};