class Solution {
public:
    
//KMP -> http://www.btechsmartclass.com/data_structures/knuth-morris-pratt-algorithm.html
    
    
    
//     int strStr(string haystack, string needle) {
    
//         int i = 0 ; int n = needle.size();
//         if(haystack.size() < n) return -1; 
        
//         while(i <= haystack.size() - n){
//             if(haystack[i] == needle[0]){
//                 if(haystack.substr(i,n) == needle) return i;
//             }
//             i++;
//         }
//         return -1;
//     }
    
/**************************KMP****************************************************/
   
//KMP -> http://www.btechsmartclass.com/data_structures/knuth-morris-pratt-algorithm.html
    
  
        int strStr(string s, string pattern) {
            
            int n = pattern.size();
            
            vector<int> lps(n , 0);
            
            //makig lps array
           int j = 0;

	lps[0] = 0; 
	int i = 1;
	while (i < n) {
		if (pattern[i] == pattern[j]) {
			lps[i] = j+1;
			i++;
            j++;
		}
		else 
		{
			
			if (j != 0) {
				j = lps[j - 1];

			}
			else
			{
				lps[i] = 0;
				i++;
			}
		}
	}
            
            int ind = -1;
            
            i = 0;
            j = 0;
            while(i < s.size() && j < n){
    
                if(s[i] == pattern[j]){
                    i++;
                    j++;
                    if(j == n){
                      return i - n;
                     
                    } 
                }
               
                else{
                    if(j == 0) i++;
                    else j = lps[j-1];
                } 
            }
    
            return ind;
        }

};