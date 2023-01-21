class Solution {
public:
    
    bool isVowel(char ch){
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || ch == 'A' ||
               ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U';
    }
    string reverseVowels(string s) {
        
        string vowels = "";
        
        for(int i = 0 ; i < s.size() ; i++){
            if(isVowel(s[i])){
                vowels+=s[i];
            }
        }
        
        int k = vowels.size()-1;
        for(int i = 0 ; i < s.size() ; i++){
            if(isVowel(s[i])){
                s[i] = vowels[k--];
            }
        }
        
        return s;
    }
};