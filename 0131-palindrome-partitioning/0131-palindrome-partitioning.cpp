class Solution {
public:
    
    /*
Time Complexity: O( (2^n) *k*(n/2) )

Reason: O(2^n) to generate every substring and O(n/2)  to check if the substring generated is a palindrome. O(k) is for inserting the palindromes in another data structure, where k  is the average length of the palindrome list.

Space Complexity: O(k * x)

Reason: The space complexity can vary depending upon the length of the answer. k is the average length of the list of palindromes and if we have x such list of palindromes in our final answer. The depth of the recursion tree is n, so the auxiliary space required is equal to the O(n).
    */
    bool isValid(string s){
        int start = 0;
        int end = s.size()-1;
        
        while(start < end){
            if(s[start++] != s[end--]) return false;
        }
        return true;
    }
    
    void f(int ind , vector<vector<string>>& ans , vector<string> helper , string s){
        
        if(ind == s.size()){
            ans.push_back(helper);//****************************************************************
            return;
        }
        
        for(int i = ind ; i < s.size() ; i++){
            string temp = s.substr(ind , i - ind + 1);
            if(isValid(temp)){
                helper.push_back(temp);
                f(i+1 , ans , helper , s);
                helper.pop_back();
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
        
        vector<vector<string>> ans;
        vector<string> helper;
        
        f(0 , ans , helper , s);
        return ans;
    }
};