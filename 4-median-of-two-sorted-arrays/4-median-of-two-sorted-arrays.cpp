class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
         vector<int> merged;
        
        for(int i = 0 ; i < nums1.size() ; i++){
            merged.push_back(nums1[i]);
        }
        
        for(int i = 0 ; i < nums2.size() ; i++){
            merged.push_back(nums2[i]);
        }
        
        sort(merged.begin(),merged.end());
        
        double ans;
        int n =(merged.size());
        
        if(merged.size()%2 != 0){
            ans = double(merged[n/2]);
        }
        
        else{
        ans =  (double(merged[n/2]) + double(merged[(n/2)-1]))/2.0;
        
        }
        
        return ans;
        
        
    }
};