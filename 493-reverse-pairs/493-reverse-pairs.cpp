class Solution {
public:
    
    
    int merge(vector<int>& nums , int left , int mid , int right){
        
        int i = left , j = mid+1;
       
        int cnt = 0;
        for(int i = left ; i <= mid ; i++){
            while(j <= right && nums[i] > 2ll*nums[j]){
                j++;
            }
            
            cnt += (j - (mid + 1));
        }
        
        vector<int> temp;
        i = left , j = mid+1;
        
        while(i <= mid && j <= right){
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
        
         while(j <= right){
            temp.push_back(nums[j++]);
        }
        
        int k;
         for(i = left , k = 0 ; i <= right ; i++,k++){
        nums[i] = temp[k];
    }
        return cnt;
        
    }
    
    int mergeSort(vector<int>& nums , int left , int right){
        
        int cnt = 0;
        if(left < right){
            
            int mid = (right + left)/2;
           cnt +=  mergeSort(nums , left , mid);
           cnt +=  mergeSort(nums , mid+1 , right);
           cnt +=  merge(nums , left , mid , right);
        }
        
        return cnt;
    }
    int reversePairs(vector<int>& nums) {
        
        return mergeSort(nums , 0 , nums.size()-1);
    }
};