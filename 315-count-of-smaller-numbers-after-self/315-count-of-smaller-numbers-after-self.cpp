class Solution {
public:
    
    //https://www.youtube.com/watch?v=_sA1xI4XK0c
    
    //awesome explanation
    
    
    void mergeSort(vector<pair<int,int>>&v , int start , int end , vector<int>& cnt){
       
        if(start < end){
            
            int mid = (start + end)/2;
            mergeSort(v , start , mid , cnt);
            mergeSort(v , mid+1 , end , cnt);
            merge(v , start , mid , end , cnt);
        }
         
    }
    
    
    void merge(vector<pair<int,int>>&v, int start , int mid , int end , vector<int>& cnt){
      
        int x = start;
        int y = mid+1;
        int z = end;
        
        
        int k = 0;
        vector<pair<int,int>> temp(end-start+1);
  
        
        while(x <= mid && y <= z){
            
           if(v[x].first <= v[y].first){
               temp[k++] = v[y++];
           }
            
           else{
               cnt[v[x].second] += z-y+1;
               temp[k++] = v[x++];
           }
              
        }
        
        while(x <= mid){
            temp[k++] = v[x++];
        }
        
        while(y <= z){
             temp[k++] = v[y++];
        }
        
        k = 0;
        for(int i = start ; i <= end ; i++){
            v[i] = temp[k++];
        }
        
    }
    
    vector<int> countSmaller(vector<int>& nums) {
        
        int n = nums.size();
        
        vector<int> cnt(n,0);
        vector<pair<int,int>> v(n);
        
        for(int i = 0 ; i < n ; i++){
             v[i] = {nums[i] , i};
        }
       mergeSort(v , 0 , n-1 , cnt);
        
        return cnt;
    }
};