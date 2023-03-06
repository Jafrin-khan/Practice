class Solution {
public:
    /*
    I read the question, First i thought in Bruteforce manner, I simply made a function "match" which return a boolean value depen upon it is subsequence or not.
I made a "ans" variable which store the count of subsequence string. I intialized to 0.
Simply traverse words array and apply this function at every element if it matchs then i increment the ans value.

class Solution {
public:
    bool match(string a,string b)
    {
        int n1 = a.size();
        int n2 = b.size();
        int i=0,j=0;
        int m=0;
        while(i!=n1 && j!=n2){
            if(a[i]==b[j]){
                m++;j++;
            }
            i++;
        }
        
        return j==n2;
    }
    
    int numMatchingSubseq(string s, vector<string>& words) {
        int ans=0;
        for(int i=0;i<words.size();i++){
            ans+=match(s,words[i]);
        }
        return ans;
    }
};
But this solution gave me TLE.

Then i though, In question it didn't tell that words array of strings contain a unique string so, string may be repeateded therefore once we calculated first why we calculated twice. simply store the value at first time and use this value for next time.
Then, I made dicitonary(unordered_map in c++) and stored the value. If it repeated then i used it.

class Solution {
public:
    bool match(string a,string b)
    {
        int n1 = a.size();
        int n2 = b.size();
        int i=0,j=0;
        int m=0;
        while(i!=n1 && j!=n2){
            if(a[i]==b[j]){
                m++;j++;
            }
            i++;
        }
        
        return j==n2;
    }
    
    int numMatchingSubseq(string s, vector<string>& words) {
        int ans=0;
        unordered_map<string,int>um;
        for(int i=0;i<words.size();i++){
            if(um.find(words[i])!=um.end())
                ans+=um[words[i]];
            else{
                um[words[i]]=match(s,words[i]);
                ans+=um[words[i]];
            }
        }
        return ans;
    }
};
    */
    bool match(string a,string b)
    {
        int n1 = a.size();
        int n2 = b.size();
        int i=0,j=0;
        while(i!=n1 && j!=n2){
            if(a[i]==b[j]){
                j++;
            }
            i++;
        }
        
        return j==n2;
    }
    
    int numMatchingSubseq(string s, vector<string>& words) {
        int ans=0;
        unordered_map<string,int>mp;
        for(int i=0;i<words.size();i++){
            if(mp.find(words[i])!=mp.end())
                ans+=mp[words[i]]; // coz zero bhi ho skta aur 1 bhi ho skta islie hum siidha jo map m stored value hai usse hi add krdenge instaed of ans++
            else{
                mp[words[i]]=match(s,words[i]);
                ans+=mp[words[i]];
            }
        }
        return ans;
    }
};