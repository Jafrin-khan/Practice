class Solution {
public:
    
    int merge(vector<int>& nums , int start , int mid , int end){
        
        int i = start;
        int j = mid + 1;
        
        int cnt = 0;
        for(int i = start ; i <= mid ; i++){
            while(j <= end && nums[i] > 2ll*nums[j] ){
                j++;
            }
            
            cnt += (j - (mid+1));
        }
        
        i = start;
        j = mid + 1;
        
        vector<int> temp;
        
        while(i <= mid && j <= end){
            
            if(nums[i] <= nums[j]){
                temp.push_back(nums[i++]);
            }
            
            else{
                temp.push_back(nums[j++]);
            }
        }
        
        while(i <= mid){
            temp.push_back(nums[i++]);
        }
        
        while(j <= end){
             temp.push_back(nums[j++]);
        }
        
        for(int i = start ,  k = 0 ; i <= end ; i++,k++){
            nums[i] = temp[k];
        }
        
        return cnt;
        
    }
    
    int mergeSort(vector<int>& nums , int start , int end){
        
        
        int cnt = 0;
        if(start < end){
            int mid = (start + end)/2;
            cnt += mergeSort(nums , start , mid);
            cnt += mergeSort(nums , mid+1 , end);
            cnt += merge(nums , start , mid , end);
            
        }
        
        return cnt;
        
    }
    int reversePairs(vector<int>& nums) {
        
          return mergeSort(nums , 0 , nums.size()-1);
        
    }
};