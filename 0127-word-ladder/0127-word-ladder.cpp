class Solution {
public:
    
//     find(wordList.begin(),wordList.end(), w) != wordList.end()
        
//     ye correct syntax hai find function ka keep that in mind , Vimp but yha use nahi kr skte
//     kyunki hamein jo word mil chuka usse serase bhi krna hoga wrna pichle word pe dobara aa jayenge
//     ye repeat hota rahega jisse TLE milega
    
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
        
    int ladderLength(string bW, string eW , vector<string>& wordList) {
        
        queue<pair<string,int>> q;//<word , dis>
        int ans = -1;
        
        unordered_set<string> st(wordList.begin(),wordList.end());
        
        q.push({bW,1});
        while(!q.empty()){
            string w = q.front().first;
            int d = q.front().second;q.pop();
           
            
            for(int i = 0 ; i < w.size() ; i++){
                char c = w[i];
                for(char ch = 'a' ; ch <= 'z' ; ch++){
                    w[i] = ch;
                    if(st.find(w) != st.end()){
                       
                        if(w == eW) return d + 1;
                        st.erase(w);///////////////////////
                        q.push({w , d+1});
                        
                    }
                }
                w[i] = c;
                
            }
        }
        
        return 0;
    }
};