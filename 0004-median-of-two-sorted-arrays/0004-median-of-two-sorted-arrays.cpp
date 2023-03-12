class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        int n = nums1.size();
        int m = nums2.size();
        
        if(n > m) return findMedianSortedArrays(nums2, nums1);
        
        int low = 0 , high = n;
        int len = n+m;
        
        while(low <= high){
            int mid = (low+high)/2;
            int cut1 = mid;
            int cut2 = (n+m+1)/2 - cut1;//to handle all even and odd cases of making partitions
            
            int l1 = cut1 > 0 ? nums1[cut1-1] : -1e9;
            int l2 = cut2 > 0 ? nums2[cut2-1] : -1e9;
            int r1 = cut1 < n ? nums1[cut1] : 1e9;
            int r2 = cut2 < m ? nums2[cut2] : 1e9;
            
            if(l1 <= r2 && l2 <= r1){
                if(len%2 != 0) return (double)max(l1,l2);
                else return ((double)max(l1,l2) + (double)min(r1,r2))/2.0;
            }
            
            else if(l1 > r2){
                high = mid-1;
            } 
                             
            else{
                low = mid+1;
            }
            
        }
                             
        return -1.0;
    }
};