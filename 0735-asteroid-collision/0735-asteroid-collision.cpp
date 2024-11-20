class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        
        stack<int> st;
        
        for(int i = 0 ; i < asteroids.size() ; i++){
            
            if(!st.empty() && ((st.top() < 0 && asteroids[i] < 0) || (st.top() > 0 && asteroids[i] > 0) || (st.top() < 0 && asteroids[i] > 0))){
                st.push(asteroids[i]);continue;
            }
            
            int elem = abs(asteroids[i]);
            
            if(!st.empty() && elem == st.top() && elem != asteroids[i]){st.pop(); continue;}
            int flag = 0;
            int notPush = 1;
            
            while(!st.empty() && ((st.top() < 0 && asteroids[i] > 0) || (st.top() > 0 && asteroids[i] < 0)) && st.top() < elem){
                flag = 1;
                st.pop();
                
                 if(!st.empty() && elem == st.top() && elem != asteroids[i]){st.pop();notPush = 0; break;}
                
                 if(!st.empty() && ((st.top() < 0 && asteroids[i] < 0) || (st.top() > 0 && asteroids[i] > 0) || (st.top() < 0 && asteroids[i] > 0))){
                 st.push(asteroids[i]);
                 break;
            }
            
            
            }
            
            if(!st.empty() && st.top() > elem) continue;
            if(notPush && (!flag || st.empty())) st.push(asteroids[i]);
            
            
        }
        
        vector<int> ans;
        
        while(!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        
        reverse(ans.begin() , ans.end());
        
        return ans;
    }
};