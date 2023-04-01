class Solution {
public:
    /*
    Approach :
1. sort the array then divide array on the two halves [0-n/2] and (n/2-n] {n = nums.size()-1}
2. pick one element from the first half starting from n/2 and move left.
3. pick one element from the second half starting from n and move left.
    */
    void wiggleSort(vector<int>& nums) {
        
        vector<int> dup = nums;
        sort(dup.begin() , dup.end());
        
        int n = nums.size()-1;
        int j = n;
        int i = n/2;
        
        int ind = 0;
        
        while(i >= 0){
          nums[ind++] = dup[i--];
          if(j > n/2) nums[ind++] = dup[j--];
        }
        

    }
};