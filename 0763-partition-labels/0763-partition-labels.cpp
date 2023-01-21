class Solution {
public:
    /*
    https://www.youtube.com/watch?v=5NCjHqx2v-k
    TC = O(N)
    SC = O(26) ~ O(1)
    */
    vector<int> partitionLabels(string s) {
        
        vector<int> lastIndex(26,-1);
        for(int i = 0 ; i < s.size() ; i++){
            lastIndex[s[i] - 'a'] = i;
        }
       
        vector<int> ans;
        
        int start = 0;
        int end = 0;
        for(int i = 0 ; i < s.size() ; i++){
            end = max(end , lastIndex[s[i]-'a']);
            if(i == end){
                ans.push_back(end-start+1);
                start = end+1;
            }
        }
        
        return ans;
        
    }
};