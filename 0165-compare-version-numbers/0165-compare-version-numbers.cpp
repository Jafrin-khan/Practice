class Solution {
public:
    
    /*
    
    version1 = "1.01", version2 = "1.001"
                i                  j
    */
    int compareVersion(string v1, string v2) {
        
        int i = 0;;
        int j = 0;
        
        while(i < v1.size() || j < v2.size()){
            
            string t1 = "";
            
            while(i < v1.size() && v1[i] !='.'){
                t1 += v1[i++];
            }
            
            string t2 = "";
            
            while(j < v2.size() && v2[j] != '.'){
                t2 += v2[j++];
            }
            
            int num1 = 0;
            int num2 = 0;
            
            if(t1.size() != 0){
                num1 = stoi(t1);
            }
            
            if(t2.size() != 0){
                num2 = stoi(t2);
            }
            
            if(num1 > num2){
                return 1;
            }
            
            if(num2 > num1){
                return -1;
            }
            
            i++;
            j++;
            
        }
        
        return 0;
        
    }
};