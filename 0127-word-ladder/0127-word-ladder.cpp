class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
        
        set<string> st;
        for(auto it : wordList) st.insert(it);
        
        queue<pair<string , int>> q;
        q.push({beginWord , 0});
        
        int ans = 1e9;
        
        while(!q.empty()){
            
            string word = q.front().first;
            int cost = q.front().second;q.pop();
            
            if(word == endWord) ans = min(ans , cost);
            
            for(int i = 0 ; i < word.size() ; i++){
                char w = word[i];
                for(char ch = 'a' ; ch <= 'z' ; ch++){
                    word[i] = ch;
                    if(st.find(word) != st.end()){
                        q.push({word , cost+1});
                        st.erase(word);
                    }
                }
                word[i] = w;
            }
        }
        
        return ans == 1e9 ? 0 : ans+1;
    }
};