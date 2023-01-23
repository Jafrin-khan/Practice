class Solution {
public:
    /*
    TC = O(N)
    */
    vector<int> asteroidCollision(vector<int>& asteroids) {
        
        stack<int> st;
        int flag = 0;
        for(int i = 0 ; i < asteroids.size() ; i++){
            int stone = asteroids[i];
            if(st.empty() || stone>0){
                st.push(stone);
                continue;
            }
            
            else{
            while(!st.empty() && stone < 0){
                if(st.top() < 0){
                    break;
                }
                if(abs(stone) == st.top()){
                    flag = 1;
                    st.pop();
                    break;
                }
                
                int top = st.top();
                st.pop();
                if(abs(stone) < abs(top)){
                    stone = top;
                }
               
            }
            
            if(!flag){
            st.push(stone);
            }
                
            flag = 0;
            }
        }
        
        vector<int> ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        
        reverse(ans.begin(),ans.end());
        
        return ans;
    }
};