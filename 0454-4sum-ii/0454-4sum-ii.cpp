class Solution {
public:
  /*  
     mp1
     1->1
     0->2
    -1->1
         
      mp2
      4->1
      2->1
      1->1
     -1->1
       
    1  cnt = 0 + 1*1
    0
    -1  cnt = 1 + 1*1
    
    return cnt = 2
     */
    
    /*
    TC = 2*O(N^2) + O(N)
    SC = O(4*N)
    */
    
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        
        unordered_map<int,int> mp1;
        unordered_map<int,int> mp2;
        int n = nums1.size();
        
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < n ; j++){
                mp1[nums1[i]+nums2[j]]++;
            }
        }
        
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < n ; j++){
                mp2[nums3[i]+nums4[j]]++;
            }
        }
        
        int cnt = 0;
        for(auto it : mp1){
            if(mp2.find(-1*it.first) != mp2.end()){
                int freq1 = it.second;
                int freq2 = mp2[-1*it.first];
                cnt += (freq1*freq2);
            }
        }
          
        return cnt;
    }
};