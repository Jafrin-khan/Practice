class Solution {
public:
    
//     int cntPairs(int start , int mid , int end , vector<int>& nums){
        
//     }
    
    int merge(int left , int mid , int right , vector<int>& arr){
        
      int i = left , j = mid+1 , k = 0;
    int invCount = 0;
    int temp[(right - left + 1)];
      for(int i=left; i<=mid; i++){
            while(j<=right && arr[i]>2ll*arr[j])
                j++;
            invCount += (j-(mid+1));
        }
     i = left , j = mid+1 ;   
    while((i <= mid) && (j <= right)){
        if(arr[i] <= arr[j]){
            temp[k++] = arr[i++];
        }
        
        else{
            
            temp[k++] = arr[j++];
        }
    }
    
    while(i <= mid){
        temp[k++] = arr[i++];
    }
    
     while(j <= right){
        temp[k++] = arr[j++];
    }
    
    for(i = left , k = 0 ; i <= right ; i++,k++){
        arr[i] = temp[k];
    }
    
    return invCount;
    }
    
    int mergeSort(int start , int end , vector<int>& nums){
        
        int cnt = 0;
        if(start < end){
            int mid = (start + end)/2;
            cnt += mergeSort(start , mid , nums);
            cnt += mergeSort(mid+1 , end , nums);
            cnt += merge(start , mid , end , nums);
        }
        
        return cnt;
    }
    int reversePairs(vector<int>& nums) {
        
        int start = 0;
        int end = nums.size()-1;
        
        return mergeSort(0 , end , nums);
    }
};