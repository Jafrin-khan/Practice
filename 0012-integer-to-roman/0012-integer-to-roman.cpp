class Solution {
public:
    /*
    TC = O(N)
    SC = O(1)
    */
    string intToRoman(int num) {
        
        int values[13] = {1000 , 900 , 500 , 400 , 100 , 90 , 50 , 40 , 10 , 9 , 5 , 4 , 1};
        string symbol[13] = {"M" , "CM" , "D" , "CD" , "C" , "XC" , "L" , "XL" , "X" , "IX" , "V" , "IV" , "I"};
        
        int i = 0;
        string ans = "";
        while(num){
            if(values[i] > num) i++;
            else{
                num -= values[i];
                ans += symbol[i];
            }
        }
        return ans;
    }
};