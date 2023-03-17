class Solution {
public:
  /*
  TC = O(NlogN)
  SC = O(N)
  */
    
    //exactly same mergeSort and merge function
    void merge(vector<int>& cnt , vector<pair<int,int>>& v , int start , int mid , int end){
      
        int i = start;
        int j = mid+1;
        
        vector<pair<int,int>> temp(end-start+1);
        int k = 0;
        
        while(i <= mid && j <= end){
            //we are arranging in desc order
            
            //sirf yahi condition h jisse hum desc order m store krtey jaare aur 'cnt' mai value bhi bhrtey jaare required waali
            if(v[i].first > v[j].first){
                cnt[v[i].second] += (end-j+1);
                temp[k++] = v[i++];
            }
            
            else{
                temp[k++] = v[j++];
            }
        }
        
        while(i <= mid){
            temp[k++] = v[i++];
        }
        
        while(j <= end){
            temp[k++] = v[j++];
        }
        
        k = 0;
        for(int i = start ; i <= end ; i++){
            v[i] = temp[k++];
        }
        
    }
    
    void mergeSort(vector<int>& cnt , vector<pair<int,int>>& v , int start , int end){
        
        if(start < end){
            int mid = (start + end)/2;
            mergeSort(cnt , v , start , mid);
            mergeSort(cnt , v , mid+1 , end);
            
            merge(cnt , v , start , mid , end);
        }
    }
    vector<int> countSmaller(vector<int>& nums) {
        
        int n = nums.size();
        
        vector<pair<int,int>> v(n);
        for(int i = 0 ; i < n ; i++){
            v[i] =  {nums[i], i};
        }
        
        vector<int> cnt(n,0);
        //mergeSort in desc order to fill cnt vector
        mergeSort(cnt , v , 0 , n-1);
        
        return cnt;
        
    }
};