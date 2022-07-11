class Solution {
public:
    string intToRoman(int num) {
        
        string symbol[] = {"M" , "CM" , "D" , "CD" ,"C","XC", "L" , "XL" , "X" , "IX" , "V" , "IV" , "I"};
        int value[] = {1000 , 900 , 500 , 400 , 100 , 90 , 50 , 40 , 10 , 9 , 5 , 4 , 1};
        
        int i = 0;   
        string ans = "";
        while(num > 0){
            
            while(value[i] > num){
                i++;
            }
            
            num -= value[i];
            ans += symbol[i];
        }
        
        return ans;
        
    }
};