class Solution {
public:
    
    int cnt = 0;
    
    void helper(vector<int>& arr , int j){
        
        if(j == arr.size()){
            cnt++;
         
        }
        
        for(int i = j ; i < arr.size() ; i++){
            
            swap(arr[i] , arr[j]);
            if(arr[j]%(j+1) == 0 || ((j+1)%(arr[j])==0)){
                helper(arr , j+1);
            }
            swap(arr[i],arr[j]);
        }
    }
    int countArrangement(int n) {
        
        vector<int> arr(n);
        
        for(int i = 0 ; i < n ; i++){
            arr[i] = i+1;
        }
        
        helper(arr , 0);
        return cnt;
        
    }
};