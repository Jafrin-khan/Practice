class Solution {
public:
    int findMinDifference(vector<string>& s) {
       vector<int> v;
        
        for(int i = 0 ; i < s.size() ; i++){
            string hrs = s[i].substr(0,2);
            string mins = s[i].substr(3);
            
            int h = stoi(hrs);
            int m = stoi(mins);
            
            v.push_back(h*60 + m);
        }
        
        sort(v.begin() , v.end());
        int ans =  1e9;
        for(int i = 1 ; i < v.size() ; i++){
            ans = min(ans , v[i]-v[i-1]);
        }
        
        ans = min(ans , 24*60-v[v.size()-1] + v[0]);
        
        return ans;
    }
};