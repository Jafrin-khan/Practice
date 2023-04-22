class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
        int size = n + m;
        
        int i = m-1 , j = n-1;
        while(size-- && i >= 0 && j >= 0){
            if(nums1[i] >= nums2[j]) nums1[size] = nums1[i--];
            else nums1[size] = nums2[j--];
        }
        
        while(j >= 0) nums1[size--] = nums2[j--];
        
    }
};