class Solution {
public:
    /*
    TC = O(N*logN)
    SC = O(1)
    */
    bool isH_Index(int h , vector<int>& citations){
        
        int cnt = citations.size();
        for(auto it : citations){
            if(it < h) cnt--;
            if(cnt < h) return false;
        }
        return true;
    }
    
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        if(n == 1) return min(citations[0] , 1);
        
        int low = 0 , high = n;// yhn high = n naaaki n-1 
        int ans;
        
        while(low <= high){
            int mid = (low + high)/2;
            if(isH_Index(mid , citations)){
                ans = mid;
                low = mid+1;
            }
            else high = mid-1;
        }
        
        return ans;
    }
};