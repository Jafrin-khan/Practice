class Solution {
public:
    //TC aur explanation pichle submission mai hai
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
        queue<pair<string,int>> q; //<word,steps>
        q.push({beginWord,1});
        
        unordered_set<string> st(wordList.begin(),wordList.end());
        
        while(!q.empty()){
            string word = q.front().first;
            int steps = q.front().second;q.pop();
            
            for(int i = 0 ; i < word.size() ; i++){
                char original = word[i];
                for(char ch = 'a' ; ch <= 'z' ; ch++){
                    word[i] = ch;
                    if(st.find(word) != st.end()){
                        if(word == endWord) return steps + 1;
                        st.erase(word);
                        q.push({word,steps+1});
                    }
                }
                word[i] = original;
            } 
        }
        
        return 0;
    }
};