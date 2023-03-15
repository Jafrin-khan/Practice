/*
Approach
(1) is_feasible() : takes the input vector wt (which contains the weights of the packages), the number of days days and a capacity capacity as input. It simulates the shipping process by keeping track of the total weight of the packages loaded on the ship. If the total weight exceeds the capacity capacity, it increments the day counter and resets the total weight to the current package weight. Finally, it checks if the number of days required to ship all packages is less than or equal to the given number of days. If so, it returns true, indicating that the given capacity is feasible. Otherwise, it returns false.

(2) The shipWithinDays() : first initializes the range of possible capacities. The minimum capacity required to ship all packages is the maximum weight of a single package, since each package must be shipped individually if its weight exceeds the capacity of the ship. The maximum capacity required is the sum of the weights of all packages, since the ship must be able to carry all the packages at once.then performs binary search on the range of capacities to find the minimum feasible capacity. For each mid-point capacity, it checks if it is feasible using the is_feasible() function. If it is feasible, it stores the capacity in the mincp variable and narrows the search range by setting the upper bound to mid-1. Otherwise, it increases the lower bound by setting it to mid+1.
The binary search continues until the range is exhausted, at which point the minimum feasible capacity stored in the mincp variable is returned.

the solution uses binary search to find the minimum capacity of the ship required to ship all packages within D days.

Complexity
Time complexity:
The time complexity of the given code is O(n log(sum of weights)) where n is the size of the input vector of weights. The is_feasible function iterates through the entire input vector once, so its time complexity is O(n). The shipWithinDays function calls the is_feasible function in a binary search loop, which runs in logarithmic time. The range for binary search is between the maximum weight and the sum of all weights, which is computed in constant time using the built-in functions max_element and accumulate respectively. Therefore, the time complexity of the entire code is O(n log(sum of weights)).
Space complexity:
The space complexity of the code is O(1) because the code uses only a constant amount of extra memory to store variables like mincp, low, high, tot_wt, and d. The input vector weights is passed by reference and is not modified, so it does not add to the space complexity.
*/

class Solution {
public:
    
    int isValid(int capacity , int days , vector<int>& weights){
        int w = 0;
        int d = 1;
        
        for(int i = 0 ; i < weights.size() ; i++){
            if(w + weights[i] <= capacity) w += weights[i];
            else{
                w = weights[i];
                d++;
            }
        }
        return d <= days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();
        
        int maxW = 0;
        int totW = 0;
        
        for(int i = 0 ; i < weights.size() ; i++){
            maxW = max(maxW , weights[i]);
            totW += weights[i];
        }
        
        int low = maxW;
        int high = totW;
        int ans;
        
        while(low <= high){
            int mid = (low + high)/2;
            if(isValid(mid , days , weights)){
                ans = mid;
                high = mid-1;
            }
            else low = mid+1;
        }
        
        return ans;
    }
};