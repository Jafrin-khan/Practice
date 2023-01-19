class FindSumPairs {
public:
    
    unordered_map<int,int> mp1;
    unordered_map<int,int> mp2;
    vector<int> nums2;
    FindSumPairs(vector<int>& a, vector<int>& b) {
       
        for(auto it : a){
            mp1[it]++;
        }
        
        for(auto it : b){
            mp2[it]++;
        }
        
        nums2 = b;
       
    }
       
    void add(int index, int val) {
           
        mp2[nums2[index]]--;
        if(mp2[nums2[index]] == 0){
            mp2.erase(nums2[index]);
        }
        
        nums2[index] += val;
        mp2[nums2[index]]++;
    }
    
    int count(int tot) {
        
         
        int count = 0;
        
        // traverse over mp1, because mp1 will have less size than mp2
        
        // if we will traverse over the mp2 then it will give TLE
        
        for(auto x : mp1)
        {
            int val = x.first;
            
            int freq = x.second;
            
            int need = tot - val;
            
            // update count
            
            if(mp2.count(need))
            {
                count += mp2[need] * freq;
            }
        }
        
        return count;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */