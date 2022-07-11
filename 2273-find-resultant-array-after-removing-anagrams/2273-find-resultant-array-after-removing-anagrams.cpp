class Solution {
public:
     bool isagm(string s1,string s2){
        map<char,int>m1,m2;
        for(auto i:s1)  m1[i]++;
        for(auto i:s2)  m2[i]++;
        return m1==m2;
    }
    vector<string> removeAnagrams(vector<string>& words) {
        for(int i=0; i < words.size()-1; i++)
            if(isagm(words[i], words[i+1]))     words.erase(words.begin() + 1 + i--);
        return words;
    }
};