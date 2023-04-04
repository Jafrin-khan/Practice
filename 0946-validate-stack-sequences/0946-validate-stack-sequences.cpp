class Solution {
public:
/*
    TC = O(N)
    SC = O(N)

*/

    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        
        int n = pushed.size();
        int m = popped.size();

        stack<int> st;
        int i = 0;
        int j = 0;

        while(i < n && j < m){
            while(!st.empty() && st.top() == popped[j]){j++; st.pop();}
            st.push(pushed[i++]);
        }

        while(!st.empty()){

            if(st.top() != popped[j]){
                return false;
            }
            st.pop();
            j++;
        }

        return true;
    }
};