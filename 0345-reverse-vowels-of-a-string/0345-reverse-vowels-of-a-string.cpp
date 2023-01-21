class Solution {
public:
/*Complexity
Time complexity: O(n)
Space complexity: O(1)
*/


    string reverseVowels(string s) {
        int i =0,j= s.size()-1;
        unordered_set<char> v({'a','e','i','o','u','A','E','I','O','U'});
        
        while(i<j){
           if(v.find(s[i])!=v.end() && v.find(s[j])!=v.end()){ 
               swap(s[i++],s[j--]);
           }
           else if(v.find(s[i])==v.end())i++;
           else if(v.find(s[j]) == v.end())j--;
               
        }

        return s;
        
    }
};