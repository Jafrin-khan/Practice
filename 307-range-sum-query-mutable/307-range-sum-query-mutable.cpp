class NumArray {
public:
    
    vector<int> v;
    int sum = 0;
    NumArray(vector<int>& nums) {
        v = nums;
        for(int i = 0 ; i < v.size() ; i++){
            sum += v[i];
        }
    }
    
    void update(int index, int val) {
        sum -= v[index];
        v[index] = val;
        sum += v[index];
        
    }
    
    int sumRange(int left, int right) {
        
        int toReturn = sum;
        
        for(int i = 0 ;i < left ; i++){
            toReturn -= v[i];
        }
        
        for(int i = right + 1 ; i < v.size() ; i++){
             toReturn -= v[i];
        }
        return toReturn;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */