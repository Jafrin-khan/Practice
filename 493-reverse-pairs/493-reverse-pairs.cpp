class Solution {
public:
   int merge(vector<int>& arr,int left , int mid , int right){
    
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

 int mergeSort(vector<int>& arr, int left , int right){
    
    int invCount = 0;
    
    if(right > left){
        int mid = (right + left)/2;
        invCount = mergeSort(arr , left , mid);
        invCount += mergeSort(arr , mid + 1 , right);
        invCount += merge(arr , left , mid , right);
    }
    
    return invCount;
}

       
    
    int reversePairs(vector<int>& arr) {
        
        int n = arr.size();
        return mergeSort(arr , 0 , n-1);
    }
};