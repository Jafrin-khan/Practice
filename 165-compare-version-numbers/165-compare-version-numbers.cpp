class Solution {
public:
    int compareVersion(string v1, string v2) {
        
        int i = 0;
        int j = 0;
        
        while(i < v1.size() || j < v2.size()){
            
            string s1 = "";
            string s2 = "";
            
            while(i < v1.size() && v1[i] != '.'){
                s1 += v1[i++];
            }
            
             while(j < v2.size() && v2[j] != '.'){
                s2 += v2[j++];
            }
            
            if(s1.size() == 0){
                s1 = "0";
            }
            
            if(s2.size() == 0){
                s2 = "0";
            }
            
            if(stoi(s1) > stoi(s2)){
                return 1;
            }
            
            if(stoi(s2) > stoi(s1)){
                return -1;
            }
            i++;
            j++;
            
        }
        
        return 0;
        
    }
};