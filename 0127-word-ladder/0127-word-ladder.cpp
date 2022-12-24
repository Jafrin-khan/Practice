class Solution {
public:
    /*
Time Complexity: O(N * M * 26)

Where N = size of wordList Array and M = word length of words present in the wordList..

Note that, hashing operations in an unordered set takes O(1) time, but if you want to use set here, then the time complexity would increase by a factor of log(N) as hashing operations in a set take O(log(N)) time.

Space Complexity:  O( N ) { for creating an unordered set and copying all values from wordList into it }

Where N = size of wordList Array.
*/
    /*
    TC = O(N*M*26)
    SC = O(N)
    */
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
        queue<pair<string , int>> q;
        q.push({beginWord , 1});
        
        unordered_set<string> st(wordList.begin() , wordList.end());
        st.erase(beginWord);
        
        while(!q.empty()){
            string word = q.front().first;
            int steps = q.front().second;
            
            q.pop();
            
            if(word == endWord){
                return steps;
            }
            
           //TC = N * wordLength * 26 * logN
            for(int i = 0 ; i < word.size() ; i++){
                char original = word[i];
                for(char ch = 'a' ; ch <= 'z' ; ch++){
                    word[i] = ch;
                    if(st.find(word) != st.end()){
                        st.erase(word);
                        q.push({word , steps+1});
                    }
                }
                
                word[i] = original;
            }
        }
        
        return 0;
        
    }
};