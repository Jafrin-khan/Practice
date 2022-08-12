class Solution {
public:
    string addBinary(string a, string b) {
        
        int c = 0;
        
        int n = a.size();
        int m = b.size();
        
        int i = n-1;
        int j = m-1;
        
        string ans = "";
        
        while(i >= 0 && j >= 0){
            
            if(a[i] == '1' && b[j] == '1'){
                
                if(c){
                    ans = "1"+ ans;
                    c = 1;
                }
                
                else{
                    ans = "0" + ans;
                    c = 1;
                }
            }
            
            else if(a[i] == '1' || b[j] == '1'){
                
                if(c){
                    ans = "0"+ ans;
                    c = 1;
                }
                
                else{
                    ans = "1" + ans;
                    c = 0;
                }
                
            }
            
            else{
                
                if(c){
                    ans = "1"+ ans;
                    c = 0;
                }
                
                else{
                    ans = "0" + ans;
                    c = 0;
                }
                
            }
            
            i--,j--;
        }
        
        while(i >= 0){
            
            if(a[i] == '1'){
                
                if(c){
                    ans = "0" + ans;
                    c = 1;
                }
                
                else{
                    ans = "1" + ans;
                    c = 0;
                }
            }
            
            else{
                
                if(c){
                    ans = "1" + ans;
                    c = 0;
                }
                
                else{
                    ans = "0" + ans;
                    c = 0;
                }
                
            }
            
            i--;
        }
        
        while(j >= 0){
            
            if(b[j] == '1'){
                
                if(c){
                    ans = "0" + ans;
                    c = 1;
                }
                
                else{
                    ans = "1" + ans;
                    c = 0;
                }
            }
            
            else{
                
                if(c){
                    ans = "1" + ans;
                    c = 0;
                }
                
                else{
                    ans = "0" + ans;
                    c = 0;
                }
                
            }
            
            j--;
        }
        
        if(c){
            ans = "1" + ans;
        }
        
        return ans;
        
    }
};