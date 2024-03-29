/*

PADHNA HAI YE APPROACH TO PADHLO...BUCKET SORT APPROACH HAI

class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if(nums.size()<2) return 0;
        
        int maxi = -1, mini = INT_MAX, n = nums.size();
        for(auto u : nums) maxi = max(maxi,u), mini = min(mini,u);
        // Since there will be n-1 gaps in between the numbers, this will be the average gap between
        // any two numbers in the array.
        // NOTE : Its very important to take the upper value of average gap, or else we will have a runtime error
        // in the index of bucket that we will find in the next step.
        int avg_gap = (int)ceil((double)(maxi-mini)/(n-1));
        // To handle cases where all the elements are same!!!
        if(avg_gap == 0) return 0;      
        /*
        Now, we can allot all the numbers a bucket, by dividing them with this average gap. Now it 
        can be easily observed that by dividing any numbers with this average gap, it is sure to fall 
        in one of the (n-1) buckets that will be formed. 
        Taking the example 1, 
                
                [3, 6, 9, 1]      =>    avg gap = ceil[(9-1)/3] ~= 3
        Now we have to find the maximum gap, therefore, it will be >= average gap.
        Alloting the buckets : [[arr[i]-min]/average_gap], for all numbers of the array, this formula will result
                               in numbers that lie in a range, and thus the result for each can be considered as 
                               the bucket index.
                               
                [3-1]/3 = 0
                [6-1]/3 = 1
                [9-1]/3 = 2
                [1-1]/3 = 0
            
              0        1      2
            1___3    ____6  ____9
            
            Now as we said, the maximum gap will be greater than or equal to the average gap, therefore, the answer
            will not lie within a bucket because its gap between the maximum and minimum element will always be
            less than the average gap, for reference, consider in bucket 2nd, we had the bucket fully filled, then
            in that case, we would have 4 as the minimum and 6 as maximum and there difference be 2. So, even in 
            worst case, we have a difference 1 less than the average. So, for the question, we only need to check
            in between the buckets. Thus we only compare the difference between the maximum of one bucket and 
            minimum of next.
        
        
        // Allocating the buckets and storing the maximum and minimum of each bucket 
        vector <int> bucket_max(n,-1), bucket_min(n,INT_MAX);
        for(int i = 0; i<n; i++){
            int index = (nums[i]-mini)/avg_gap;
            bucket_min[index] = min(bucket_min[index],nums[i]);
            bucket_max[index] = max(bucket_max[index],nums[i]);
        }
        
        // After filling the min and max arrays, we just need to compare...
        int prev = mini, ans = 0;
        for(int i = 0; i<bucket_min.size(); i++){
            if(bucket_max[i] == -1) continue;
            ans = max(ans,bucket_min[i]-prev);
            prev = bucket_max[i];
        }
        // We need to compare with the last element which is maximum...
        ans = max(ans,maxi-prev);
        return ans;
    }
};
*/
class Solution {
public:
    int maximumGap(vector<int>& nums) {
        
        int n = nums.size();
        if(n < 2) return 0;
        
        set<int> st;

        for(int i = 0 ; i < n ; i++){
            st.insert(nums[i]);
        }
        
        int prev = -1;
        int maxDiff = 0;
        
        for(auto it : st){
            if(prev == -1) prev = it;
            else{
                maxDiff = max(maxDiff , it - prev);
                prev = it;
            }
        }
        
        return maxDiff;
        
    }
};