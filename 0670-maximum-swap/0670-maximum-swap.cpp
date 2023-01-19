class Solution {
public:
    /*
    TC = O(N)
    SC = O(1)
    */
    int maximumSwap(int num) {
        
        string dup = std:: to_string(num);
        int maxInd = -1;
        int maxNum = -1;
        int left = -1;
        int right = -1;
        
        for(int i = dup.size()-1 ; i >= 0 ; i--){
            
            if(dup[i] > maxNum){
                maxNum = dup[i];
                maxInd = i;
                continue;
            }
            
            if(dup[i] < maxNum){
                right = maxInd;
                left = i;
            }
        }
       
    //means num is already in order
       if (left == -1) return num;
       swap(dup[left],dup[right]);
        return std:: stoi(dup);
        
    }
};