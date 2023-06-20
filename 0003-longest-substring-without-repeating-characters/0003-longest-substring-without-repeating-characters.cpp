class Solution {
public:
    
    int lengthOfLongestSubstring(string str){
        
        //WHY THIS COMMENTED CODE NOT WORKING CHECK FROM FRIEND
//         if(s.size() == 0) return 0;
       
//         vector<int> v(26,0);
        
//         int left = 0;
//         int right = 0;
        
//         int ans = 0;
        
//         while(right < s.size()){
//             v[s[right] - 'a']++;
            
//             if(v[s[right] - 'a'] > 1){
//                 char ch = s[right];
//                 while(left < right && (v[s[right] - 'a'] > 1)){
//                     v[s[left] - 'a']--;
//                     left++;
//                 }
//             }
            
//             ans = max(ans , right - left + 1);
//             right++;
//         }
        
//         return ans;
        
          if(str.size()==0)  return 0;
          int maxans = INT_MIN;
          unordered_set < int > set;
          int l = 0;
          for (int r = 0; r < str.length(); r++) // outer loop for traversing the string
          {
            if (set.find(str[r]) != set.end()) //if duplicate element is found
            {
              while (l < r && set.find(str[r]) != set.end()) {
                set.erase(str[l]);
                l++;
              }        
            }
            set.insert(str[r]);
            maxans = max(maxans, r - l + 1);
          }
          return maxans;
    }
};