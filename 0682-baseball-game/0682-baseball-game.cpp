class Solution {
public:
    /*
    TC = O(N)
    SC = O(N)
    */
    int calPoints(vector<string>& s) {
        
        int ans = 0;
        int n = s.size();
        stack<int> st;
        
        for(int i = 0 ; i < n ; i++){
            
            if(s[i] == "+"){
                int top1 = st.top();st.pop();
                int top2 = st.top();st.push(top1);
                st.push(top1+top2);
            }
            else if(s[i] == "D"){
                st.push(st.top()*2);
            }
            else if(s[i] == "C"){
                int top = st.top();
                st.pop();
            }
            else{
                int num = std:: stoi(s[i]);
                st.push(num);
            }
           
        }
        
        while(!st.empty()){
            ans+=st.top();st.pop();
        } 
        
        return ans;
        
    }
};