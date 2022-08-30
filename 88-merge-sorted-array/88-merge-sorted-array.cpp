class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
        if(n == 0){
            return;
        }
        
       
        int i = m-1;
        int j = n-1;
        int k = (n+m-1);
        
         if(m == 0){
           nums1 = nums2;
             return;
        }
        
        
        while(j >= 0 && i >= 0){
            
            if(nums1[i] >= nums2[j]){
                nums1[k--] = nums1[i--];
            }
            
            else{
                nums1[k--] = nums2[j--];
            }
        }
        
        while(j >= 0){
            nums1[k--] = nums2[j--];
        }
        
        while(i >= 0){
            nums1[k--] = nums1[i--];
        }
        
        
        
    }
};