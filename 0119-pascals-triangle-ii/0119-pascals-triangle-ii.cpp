class Solution {
public:
    
    /*
    TC = O(N^2)
    SC = O(N^2)
    */
    vector<int> getRow(int n) {
        
        vector<vector<int>> track;
        for(int i = 0 ; i <= n ; i++){
            vector<int> v(i+1,1);
            for(int j = 1 ; j < i ; j++){
                vector<int> last = track.back();
                v[j] = last[j-1] + last[j];
            }
            
            track.push_back(v);
        }
        
        return track.back();
    }
};