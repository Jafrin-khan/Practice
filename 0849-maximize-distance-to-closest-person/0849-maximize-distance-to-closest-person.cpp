class Solution {
public:
    
    //khudka logic
    
    /*
    TC = O(N) + O(N/2) ~ O(N)
    SC = O(1)
    */
    int maxDistToClosest(vector<int>& seats) {
        
        int currMax = -1;
        int n = seats.size();
        int pos;
        
        for(int i = 0 ; i < n ; i++){
            if(seats[i] == 0){
                int left = i-1;
                int right = i+1;
                
                int L = -1,R = -1;
                while(left >= 0){
                    if(seats[left] == 1){
                        L = left;
                        break;
                    }
                    left--;
                }
                
                while(right < n){
                    if(seats[right] == 1){
                        R = right;
                        break;
                    }
                    right++;
                }
            
                int mini = min(i-left, right-i);
                
                if(mini > currMax){
                    pos = i;
                    currMax = mini;
                }
                
                if(i == 0 && R > currMax){
                    pos = i;
                    currMax = R;
                }
                
                if(i == n-1 && (n-L-1) > currMax){
                    pos = i;
                    currMax = n-L-1;
                }
            }
        }
        
        return currMax;
        
    }
};