class Solution {
    
    //https://www.youtube.com/watch?v=fWS0TCcr-lE
    
    /*
    TC = 
    SC = 
    */
    vector<int> v;
public:
    Solution(vector<int>& w) {
        v.push_back(w[0]);
        for(int i = 1 ; i < w.size() ; i++) v.push_back(w[i] + v.back());//storing prefix sum
    }
    
    int pickIndex() {
        int randWeight = rand()%(v.back());//finding the random No to pick weight
        return upper_bound(v.begin() , v.end() , randWeight)-v.begin();//choosing the bucket ...end - start...to get the range in number line
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */