class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        
        vector<int> char_map(26);
        
        for(auto c : tasks){
            // idx 0 have freq of A , idx b have freq of B and xo on
            char_map[c-'A']++;
        }
        
        sort(char_map.begin() , char_map.end());
        //0 based indexing.....minus 1 isliye kyunki last execution k bad idle nhi h
        int max_val = char_map[25]-1;
        int idle_slots = max_val*n;
        
        for(int i = 24 ; i >= 0 ; i--){
            idle_slots -= min(char_map[i] , max_val);
        }
        
        return idle_slots > 0 ? idle_slots + tasks.size() : tasks.size();
    }
};