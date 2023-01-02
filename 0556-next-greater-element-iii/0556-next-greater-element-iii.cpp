class Solution {
public:
    int nextGreaterElement(int n) {
        
        string temp = to_string(n);
        next_permutation(temp.begin() , temp.end());
        
        if(temp == to_string(n)){
            return -1;
        }
        //string to long int
        int newInt = stol(temp);
        
        if(newInt > n){
            return newInt;
        }
        
        return -1;
    }
};