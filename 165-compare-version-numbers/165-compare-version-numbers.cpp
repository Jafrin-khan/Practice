class Solution {
public:
    int compareVersion(string v1, string v2) {
        
        int n = v1.size();
        int m = v2.size();
        
        int i = 0;
        int j = 0;
        
        while(i < n || j < m){
            
            string temp1 = "";
            string temp2 = "";
            
            while(i < n && v1[i] !='.'){
                temp1 += v1[i++];
            }
            
            while(j < m && v2[j] !='.'){
                temp2 += v2[j++];
            }
            
            if(temp1.size() == 0){
                temp1 = "0";
            }
            
            if(temp2.size() == 0){
                temp2 = "0";
            }
             
            if(stoi(temp1) > stoi(temp2)){
                return 1;
            }
            
            if(stoi(temp1) < stoi(temp2)){
                return -1;
            }
            
            i++;
            j++;
        }
     
        
        return 0;
    }
};