class Solution {
public:
    int longestMountain(vector<int>& arr) {
      /*  KHUDKA SOLUTION...CHECK WHY THIS CODE NOT WORKING
        int n = arr.size();
        if(n < 3) return 0;
        
        int i = 0 , j = 1;
        int ans = 0;
        
        while(i < n && j < n){
            if(arr[j] > arr[i]){
                while(j < n && arr[j] > arr[j-1])j++;
                while(j < n && arr[j] < arr[j-1])j++;
                ans = max(ans,j-i);
            }
            else{
                j++;
                i++;
            }
        }
        
        return ans;
       */ 
        
        //PEAK AND VALLY APPROACH
        	 int maxl = 0, i = 1;
        
        while(i < arr.size()) {
            
            int peak = 0, valley = 0;
            while(i < arr.size() && arr[i] > arr[i - 1]) peak++, i++;
            while(i < arr.size() && arr[i] < arr[i - 1]) valley++, i++;
            if(peak > 0 && valley > 0) maxl = max(maxl, peak + valley + 1);
            else if(!peak && !valley) i++;
        }
        return maxl;
    }
};