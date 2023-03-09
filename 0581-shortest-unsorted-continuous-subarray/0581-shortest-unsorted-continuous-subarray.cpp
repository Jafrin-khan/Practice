class Solution {
public:
    /* brute
    int findUnsortedSubarray(vector<int>& nums) {
        
        vector<int> sorted = nums;
        sort(sorted.begin() , sorted.end());
        
        int start = -1;
        for(int i = 0 ; i < nums.size() ; i++){
            if(nums[i] != sorted[i]){ start = i;break;}
        }
        int end = -1;
        for(int i = nums.size()-1 ; i >= 0 ; i--){
            if(nums[i] != sorted[i]) {end = i ; break;}
        }
        
        if(start == -1 && end == -1) return 0;
        return end-start+1;
    }*/
    
    //optimised
     int findUnsortedSubarray(vector<int>& nums) {
        int start = 0 , end = nums.size()-1;
        
        while(start<end)
        {   
            bool flag = true;
           // First we will  move forward from current start and check increasing condition
            if(nums[start]<= nums[start+1])
                start++ , flag = false;
           // Similarly we move backward from curr end and check decreasing condition
            if(nums[end]>= nums[end-1])
                end--, flag = false;
            
            if(flag) break;
        }

        // IF Crossed Returned
        if(start>=end)
            return 0;
        
        // IF same values before or ahead
        // for Case like given below we will have stop at index 
        // start = 3 , end = 4
        // but we need to move backward from start and forward from end
        // Eg 1 2 2 2 3 3 3

            int j = end+1;
            while(j<nums.size() && nums[j] == nums[end])
                j++;
            end = j-1;
            
            int i = start-1;
            while(i>=0 && nums[i] == nums[start])
                i--;
            start = i+1;

        //Now We will find minimum and maximum in curr window
        // and move backward from curr till we dont get lesser value than min
        // similarly we move forward from end till we dont get greater val than maxi

        int mini = INT_MAX;
        int maxi = INT_MIN;
        
        int k = start+1 ;
        while(k<nums.size() && k<= end)
        mini = min(mini , nums[k++]);

        k = end-1;
        while(k>= 0 && k>= start)
        maxi = max(maxi , nums[k--]);
        
        while(end<nums.size() && nums[end]<maxi)
        end++;

        while(start>=0 && nums[start] > mini)
        start--;
        
        end--;
        start++;

        // return ans
        return end-start+1;
    }
};

// Some good Test cases
// [1,3,3,3,3,3,2,2,2]
// [1,2,4,5,6.3]
// [1,3,5,2,4]
// [2,1,5,3,4]


